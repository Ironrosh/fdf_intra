/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:37:13 by mhorpe            #+#    #+#             */
/*   Updated: 2020/09/19 01:44:12 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		get_height(char *path)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	if ((fd = open(path, O_RDONLY, 0)) < 0)
		err_exit("Can't open this file");
	line = NULL;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
		line = NULL;
	}
	close(fd);
	if (height == 0)
		err_exit("Error: Empty file!");
	return (height);
}

int		get_width(char *path)
{
	t_width	w;

	if ((w.fd = open(path, O_RDONLY, 0)) < 0)
		err_exit("Can't open this file");
	w.line = NULL;
	w.flag = 0;
	while (get_next_line(w.fd, &w.line))
	{
		w.trim = ft_strtrim(w.line);
		if (w.flag == 1)
		{
			if (ft_count_words(w.trim, ' ') != (size_t)w.width)
				err_exit("Error: Width must be the same everywhere");
		}
		else
			w.flag = 1;
		w.width = ft_count_words(w.trim, ' ');
		free(w.trim);
		free(w.line);
		w.line = NULL;
	}
	close(w.fd);
	if (w.width == 0)
		err_exit("Error: Empty file!");
	return (w.width);
}

void	get_row(int *z_arr, char *line, int width)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (i < width)
	{
		z_arr[i] = ft_atoi(split[i]);
		ft_strdel(&line);
		i++;
	}
	ft_free2darr((void**)split, i);
}

void	read_from_file(char *path, t_fdf *fdf)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fdf->height = get_height(path);
	if (!(fdf->z_coords = (int**)malloc(sizeof(int*) * (fdf->height + 1))))
		err_exit("Failed to allocate memory");
	fdf->width = get_width(path);
	while (i < fdf->height)
		if (!(fdf->z_coords[i++] = \
			(int*)malloc(sizeof(int) * (fdf->width + 1))))
			err_exit("Failed to allocate memory");
	if ((fd = open(path, O_RDONLY)) < 0)
		err_exit("Can't open this file");
	line = NULL;
	i = 0;
	while (get_next_line(fd, &line) && i < fdf->height)
	{
		get_row(fdf->z_coords[i], line, fdf->width);
		line = NULL;
		i++;
	}
	fdf->z_coords[i] = NULL;
	close(fd);
}

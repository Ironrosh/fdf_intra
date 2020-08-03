/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:12:45 by mhorpe            #+#    #+#             */
/*   Updated: 2020/02/28 16:49:55 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		temp_function_one(int i)
{
	if (i == -1)
		return (-1);
	return (0);
}

static char		*temp_function_two(char *fds, char **line)
{
	int		test;

	if (ft_strchr(fds, '\n') > 0)
		test = 1;
	else
		test = 0;
	if (test == 1)
		*line = ft_strsub(fds, 0, ft_strchr(fds, '\n') - fds);
	else
		*line = ft_strdup(fds);
	fds = ft_strsub(fds, (unsigned int)(ft_strlen(*line) + test),
			(size_t)(ft_strlen(fds) - (ft_strlen(*line) + test)));
	return (fds);
}

int				get_next_line(const int fd, char **line)
{
	static char	*fds[10000];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			i;

	if (fd < 0 || (!fds[fd] && !(fds[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ft_strchr(fds[fd], '\n') && (i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		temp = fds[fd];
		fds[fd] = ft_strjoin(fds[fd], buff);
		ft_strdel(&temp);
	}
	if (i == -1 || !*(temp = fds[fd]))
		return (temp_function_one(i));
	fds[fd] = temp_function_two(fds[fd], line);
	ft_strdel(&temp);
	if (!ft_strlen(*line) && !fds[fd])
		return (0);
	return (1);
}

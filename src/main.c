/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:36:07 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 13:58:35 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf *fdf)
{
	fdf->scale = 14;
	fdf->shift_axis = 300;
	fdf->shift_ordinate = 300;
	fdf->proj_type = 1;
	if (!(fdf->mlx_ptr = mlx_init()))
		err_exit("Error: Failed to allocate memory");
	if (!(fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 1000, 1000, "fdf")))
		err_exit("Error: Failed to allocate memory");
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, 1000, 1000)))
		err_exit("Error: Init() failed");
	fdf->data_addr = mlx_get_data_addr(fdf->img_ptr, &(fdf->bits_per_pixel),
										&(fdf->size_line), &(fdf->endian));
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf file_name\n");
		return (0);
	}
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	read_from_file(argv[1], fdf);
	find_minmax(fdf);
	fdf_init(fdf);
	draw_all(fdf);
	mlx_key_hook(fdf->win_ptr, key_pressed, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, close_win, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}

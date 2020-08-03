/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 18:08:27 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 12:14:01 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			close_win(void *param)
{
	(void)param;
	exit(0);
}

void		clear_window(t_fdf *fdf)
{
	int		i;

	i = 0;
	while (i < 1000 * 1000 * (fdf->bits_per_pixel / 8))
		fdf->data_addr[i++] = 0;
}

void		draw_all(t_fdf *fdf)
{
	draw_map(fdf);
	txt_help(fdf);
}

void		ez_bonus(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			fdf->z_coords[y][x] *= -1;
			x++;
		}
		y++;
	}
	find_minmax(fdf);
}

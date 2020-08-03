/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:22:18 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 12:52:12 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_minmax(t_fdf *fdf)
{
	int x;
	int	y;

	y = 0;
	fdf->min_z = fdf->z_coords[0][0];
	fdf->max_z = fdf->z_coords[0][0];
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (fdf->min_z > fdf->z_coords[y][x])
				fdf->min_z = fdf->z_coords[y][x];
			if (fdf->max_z < fdf->z_coords[y][x])
				fdf->max_z = fdf->z_coords[y][x];
			x++;
		}
		y++;
	}
}

t_point	create_point(int x, int y, t_fdf *fdf)
{
	t_point		point;

	point.x = x;
	point.y = y;
	point.z = fdf->z_coords[y][x];
	point.color = get_base_color(point.z, fdf);
	return (point);
}

void	txt_help(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 10, 0xffffff,\
									"Move wireframe: Arrow keys");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 25, 0xffffff,\
									"Zoom in/out: +/- keys");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 40, 0xffffff,\
									"Change projection type: T");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 57, 0xffffff,\
									"Rotation: W/S/A/D/Z/X (R for reset)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 72, 0xffffff,\
									"Rotation by 90 degrees: Y/H/G/J/B/N");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 87, 0xffffff,\
									"Invert by Z: I");
}

void	pix_put(t_fdf *fdf, t_point p, int color)
{
	int		i;

	if (p.x >= 0 && p.x < 1000 && p.y >= 0 && p.y < 1000)
	{
		i = (p.x * fdf->bits_per_pixel / 8) + (p.y * fdf->size_line);
		fdf->data_addr[i] = color;
		i++;
		fdf->data_addr[i] = color >> 8;
		i++;
		fdf->data_addr[i] = color >> 16;
	}
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

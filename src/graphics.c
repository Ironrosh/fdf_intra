/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:17:31 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 14:37:00 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		iso_translation(t_point *point)
{
	int temp_x;
	int temp_y;

	temp_x = point->x;
	temp_y = point->y;
	point->x = (temp_x - temp_y) * cos(0.523599);
	point->y = -(point->z) + (temp_x + temp_y) * sin(0.523599);
}

static void	norminette_has_no_power(t_point *a, t_point *b, t_fdf *fdf)
{
	a->x = a->x * fdf->scale;
	a->y = a->y * fdf->scale;
	b->x = b->x * fdf->scale;
	b->y = b->y * fdf->scale;
	a->z = a->z * fdf->scale;
	b->z = b->z * fdf->scale;
	if (fdf->proj_type == 1)
	{
		rotation(a, b, fdf);
		iso_translation(a);
		iso_translation(b);
	}
	a->x = a->x + fdf->shift_axis;
	a->y = a->y + fdf->shift_ordinate;
	b->x = b->x + fdf->shift_axis;
	b->y = b->y + fdf->shift_ordinate;
}

static void	sign_assign(t_point *sign, t_point *a, t_point *b)
{
	if (a->x < b->x)
		sign->x = 1;
	else
		sign->x = -1;
	if (a->y < b->y)
		sign->y = 1;
	else
		sign->y = -1;
}

void		mlx_line(t_point a, t_point b, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	norminette_has_no_power(&a, &b, fdf);
	delta.x = abs(b.x - a.x);
	delta.y = abs(b.y - a.y);
	sign_assign(&sign, &a, &b);
	error[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		pix_put(fdf, cur, get_color(cur, a, b, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void		draw_map(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				mlx_line(create_point(x, y, fdf),
					create_point(x + 1, y, fdf), fdf);
			if (y < fdf->height - 1)
				mlx_line(create_point(x, y, fdf),
					create_point(x, y + 1, fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
}

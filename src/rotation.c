/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 16:48:00 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 14:38:40 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	rotate_x(int *y, int *z, double alpha)
{
	int temp_y;

	temp_y = *y;
	*y = temp_y * cos(alpha) + *z * sin(alpha);
	*z = -temp_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int temp_x;

	temp_x = *x;
	*x = temp_x * cos(beta) + *z * sin(beta);
	*z = -temp_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int temp_x;
	int temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = temp_x * cos(gamma) - temp_y * sin(gamma);
	*y = temp_x * sin(gamma) + temp_y * cos(gamma);
}

void	rotation(t_point *a, t_point *b, t_fdf *fdf)
{
	rotate_x(&a->y, &a->z, fdf->alpha);
	rotate_x(&b->y, &b->z, fdf->alpha);
	rotate_y(&a->x, &a->z, fdf->beta);
	rotate_y(&b->x, &b->z, fdf->beta);
	rotate_z(&a->x, &a->y, fdf->gamma);
	rotate_z(&b->x, &b->y, fdf->gamma);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:16:54 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 13:12:40 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

int	get_base_color(int z, t_fdf *fdf)
{
	double	perc;

	perc = percent(fdf->min_z, fdf->max_z, z);
	if (perc < 0.2)
		return (C_TAPESTRY);
	else if (perc < 0.4)
		return (C_DANUBE);
	else if (perc < 0.6)
		return (C_CGREEN);
	else if (perc < 0.8)
		return (C_TULIP_TREE);
	else
		return (C_CHEST_ROSE);
}

int	mix_colors(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	perc;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		perc = percent(start.x, end.x, current.x);
	else
		perc = percent(start.y, end.y, current.y);
	r = mix_colors((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, perc);
	g = mix_colors((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, perc);
	b = mix_colors(start.color & 0xFF, end.color & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}

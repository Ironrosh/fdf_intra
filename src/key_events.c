/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:36:56 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 12:22:51 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	god_please_there_are_too_many_keys(int key, t_fdf *fdf)
{
	if (key == 5)
		fdf->alpha -= 1.5708;
	else if (key == 38)
		fdf->alpha += 1.5708;
	else if (key == 16)
		fdf->beta += 1.5708;
	else if (key == 4)
		fdf->beta -= 1.5708;
	else if (key == 16)
		fdf->beta += 1.5708;
	else if (key == 11)
		fdf->gamma -= 1.5708;
	else if (key == 45)
		fdf->gamma += 1.5708;
}

static void	rotation_reset(t_fdf *fdf)
{
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
}

static void	key_extend(int key, t_fdf *fdf)
{
	if (key == 17)
	{
		fdf->proj_type = (fdf->proj_type == 1) ? 0 : 1;
		rotation_reset(fdf);
	}
	else if (key == 0)
		fdf->alpha -= 0.05;
	else if (key == 2)
		fdf->alpha += 0.05;
	else if (key == 13)
		fdf->beta += 0.05;
	else if (key == 1)
		fdf->beta -= 0.05;
	else if (key == 6)
		fdf->gamma -= 0.05;
	else if (key == 7)
		fdf->gamma += 0.05;
	else if (key == 15)
		rotation_reset(fdf);
	else if (key == 34)
		ez_bonus(fdf);
	else if (key == 16 || key == 5 || key == 4 || key == 38 || key == 11 \
			|| key == 45)
		god_please_there_are_too_many_keys(key, fdf);
}

static int	check_key(int key)
{
	if ((key >= 123 && key <= 126) || key == 24 || key == 27 || key == 12 \
		|| key == 17 || key == 53 || key == 0 || key == 2 || key == 13 \
		|| key == 1 || key == 6 || key == 7 || key == 15 || key == 34 \
		|| key == 16 || key == 5 || key == 4 || key == 38 || key == 11 \
		|| key == 45)
		return (1);
	return (0);
}

int			key_pressed(int key, t_fdf *fdf)
{
	if (check_key(key))
	{
		if (key == 53)
			exit(0);
		else if (key == 126)
			fdf->shift_ordinate -= 10;
		else if (key == 125)
			fdf->shift_ordinate += 10;
		else if (key == 123)
			fdf->shift_axis -= 10;
		else if (key == 124)
			fdf->shift_axis += 10;
		else if (key == 24)
			fdf->scale++;
		else if (key == 27)
			(fdf->scale > 0) ? fdf->scale-- : fdf->scale;
		else if (key == 17 || (key >= 0 && key <= 2) || key == 13 \
				|| key == 6 || key == 7 || key == 15 || key == 34 \
				|| key == 16 || key == 5 || key == 4 || key == 38 || key == 11 \
				|| key == 45)
			key_extend(key, fdf);
		clear_window(fdf);
		draw_all(fdf);
	}
	return (0);
}

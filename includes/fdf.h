/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 16:29:02 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 13:21:03 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include <unistd.h>

typedef struct	s_width
{
	int			fd;
	int			width;
	char		*line;
	char		*trim;
	int			flag;
}				t_width;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**z_coords;
	int			scale;
	int			shift_axis;
	int			shift_ordinate;
	void		*mlx_ptr;
	void		*win_ptr;
	int			proj_type;
	int			min_z;
	int			max_z;
	double		alpha;
	double		beta;
	double		gamma;
	void		*img_ptr;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_fdf;

void			read_from_file(char *path, t_fdf *fdf);
void			mlx_line(t_point a, t_point b, t_fdf *fdf);
int				key_pressed(int key, t_fdf *fdf);
void			draw_map(t_fdf *fdf);
void			txt_help(t_fdf *fdf);
void			draw_all(t_fdf *fdf);
void			find_minmax(t_fdf *fdf);
int				get_base_color(int z, t_fdf *fdf);
double			percent(int start, int end, int current);
t_point			create_point(int x, int y, t_fdf *fdf);
int				get_color(t_point current, t_point start, t_point end,
							t_point delta);
void			rotate_z(int *x, int *y, double gamma);
void			rotate_y(int *x, int *y, double beta);
void			rotate_x(int *x, int *y, double alpha);
void			rotation(t_point *a, t_point *b, t_fdf *fdf);
int				close_win(void *param);
void			pix_put(t_fdf *fdf, t_point p, int color);
void			err_exit(char *s);
void			ez_bonus(t_fdf *fdf);
void			clear_window(t_fdf *fdf);
void			check_numbers(char **split);
int				check_num_string(char *line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:26:02 by aoizel            #+#    #+#             */
/*   Updated: 2023/12/01 13:45:10 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"
# include "libftprintf/ft_printf/ft_printf.h"
# include <math.h>
# include <fcntl.h>
# ifndef GRAD_S
#  define GRAD_S 0x1a1d1e
# endif
# ifndef GRAD_E
#  define GRAD_E 0xff7e00
# endif
# ifndef MAX_ITER
#  define MAX_ITER 200
# endif

typedef struct s_win_param
{
	void				*mlx_p;
	void 				*mlx_w;
	double				center_x;
	double				center_y;
	unsigned int		size_x;
	unsigned int		size_y;
	unsigned int		zoom;
	char				fractal;
	double				j_real_param;
	double				j_im_param;
	int					max_iter;
	unsigned int		*color_range;
}	t_win_param;


unsigned int		*color_range(int max);
void				draw_mandelbrot(t_win_param *win_param);
void				draw_julia(t_win_param *win_param);
void				draw_burning_ship(t_win_param *win_param);
void				draw_tricorn(t_win_param *win_param);
void				draw_tricorn(t_win_param *win_param);
double				ft_atof(char *nptr);
int					win_close(t_win_param *win_param);
int					mouse_hook(int button, int x, int y, t_win_param *win_param);
int					key_hook(int key, t_win_param *win_param);
void				draw(t_win_param *win_param);

#endif

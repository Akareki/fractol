/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:13:40 by aoizel            #+#    #+#             */
/*   Updated: 2023/12/01 11:16:25 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(double x, double y, t_win_param *win_param)
{
	int		i;
	double	a;
	double	a2;
	double	b;
	double	b2;

	i = 0;
	a = x;
	b = y;
	a2 = 0;
	b2 = 0;
	while (i < win_param->max_iter - 1 && a2 + b2 < 4)
	{
		a2 = a * a;
		b2 = b * b;
		b = (a + a) * b + win_param->j_im_param;
		a = a2 - b2 + win_param->j_real_param;
		i++;
	}
	return (i);
}

void	draw_julia(t_win_param *win_param)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	c;

	j = 0;
	while (j < win_param->size_y)
	{
		i = 0;
		while (i < win_param->size_x)
		{
			c = julia_iter(win_param->center_x
					+ (((double)i - win_param->size_x / 2) / win_param->zoom),
					win_param->center_y
					+ ((double)j - win_param->size_y / 2) / win_param->zoom,
					win_param);
			mlx_pixel_put(win_param->mlx_p, win_param->mlx_w, i, j,
				win_param->color_range[c]);
			i++;
		}
		j++;
	}
}

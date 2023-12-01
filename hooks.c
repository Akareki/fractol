/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:10:24 by aoizel            #+#    #+#             */
/*   Updated: 2023/12/01 11:10:55 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_win_param *win_param)
{
	if (win_param->fractal == 'm')
		draw_mandelbrot(win_param);
	if (win_param->fractal == 'b')
		draw_burning_ship(win_param);
	if (win_param->fractal == 't')
		draw_tricorn(win_param);
	if (win_param->fractal == 'j')
		draw_julia(win_param);
}

int	win_close(t_win_param *win_param)
{
	free(win_param->color_range);
	mlx_destroy_window(win_param->mlx_p, win_param->mlx_w);
	mlx_destroy_display(win_param->mlx_p);
	exit(0);
}

void	switch_m_j(t_win_param *win_param)
{
	if (win_param->fractal == 'm')
	{
		win_param->fractal = 'j';
		win_param->j_real_param = win_param->center_x;
		win_param->j_im_param = win_param->center_y;
	}
	else if (win_param->fractal == 'j')
	{
		win_param->fractal = 'm';
		win_param->center_x = win_param->j_real_param;
		win_param->center_y = win_param->j_im_param;
	}
}

int	mouse_hook(int button, int x, int y, t_win_param *win_param)
{
	if (button == 2 || button == 4 || button == 5)
	{
		win_param->center_x = ((double)x - (double)win_param->size_x / 2)
			/ win_param->zoom + win_param->center_x;
		win_param->center_y = ((double)y - (double)win_param->size_y / 2)
			/ win_param->zoom + win_param->center_y;
		if (button == 2)
			switch_m_j(win_param);
		if (button == 4 && win_param->zoom < 2147483647)
			win_param->zoom *= 2;
		if (button == 5 && win_param->zoom > 100)
			win_param->zoom /= 2;
		draw(win_param);
	}
	return (0);
}

int	key_hook(int key, t_win_param *win_param)
{
	if (key == 0xff1b)
		win_close(win_param);
	if (key == 0xff51)
		win_param->center_x -= (double)win_param->size_x / 8 / win_param->zoom;
	if (key == 0xff52)
		win_param->center_y -= (double)win_param->size_y / 8 / win_param->zoom;
	if (key == 0xff53)
		win_param->center_x += (double)win_param->size_x / 8 / win_param->zoom;
	if (key == 0xff54)
		win_param->center_y += (double)win_param->size_y / 8 / win_param->zoom;
	if (win_param->fractal == 'j')
	{
		if (key == 0x0068)
			win_param->j_real_param -= 0.005;
		if (key == 0x006a)
			win_param->j_im_param -= 0.005;
		if (key == 0x006b)
			win_param->j_im_param += 0.005;
		if (key == 0x006c)
			win_param->j_real_param += 0.005;
	}
	draw(win_param);
	return (0);
}

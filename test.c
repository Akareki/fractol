/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:25:29 by aoizel            #+#    #+#             */
/*   Updated: 2023/11/29 16:06:12 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"



int	color_range(int c)
{
	int	gradient[10];

	gradient[0] = 0xfafa6e;
	gradient[1] = 0xc4ec74;
	gradient[2] = 0x92dc7e;
	gradient[3] = 0x64c987;
	gradient[4] = 0x39b48e;
	gradient[5] = 0x089f8f;
	gradient[6] = 0x00898a;
	gradient[7] = 0x08737f;
	gradient[8] = 0x215d6e;
	gradient[9] = 0x2a4858;
	return (gradient[c / 20]);
}

int	mandelbrot_iter(double x, double y)
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
	while (i < 190 && a2 + b2 < 4)
	{
		a2 = a * a;
		b2 = b * b;
		b = (a + a) * b + y;
		a = a2 - b2 + x;
		i++;
	}
	return (i);
}


void	draw_mandelbrot(t_win_param *win_param)
{
	unsigned int	i;
	unsigned int	j;
	double	c;

	j = 0;
	while (j < win_param->size_y)
	{
		i = 0;
		while (i < win_param->size_x)
		{
			c = mandelbrot_iter(win_param->center_x + (((double)i - win_param->size_x / 2) / win_param->zoom), win_param->center_y + ((double)j - win_param->size_y / 2) / win_param->zoom);
			mlx_pixel_put(win_param->mlx_p, win_param->mlx_w, i, j, color_range(c));
			i++;
		}
		j++;
	}
}

void	draw_square(void *mlx_p, void *mlx_w, int x, int y, int c)
{
	int	i;
	int	j;

	j = 0;
	while (j <= c)
	{
		i = 0;
		while (i <= c)
		{
			mlx_pixel_put(mlx_p, mlx_w, x + i, y + j, 0x00FFFFFF);
			i++;
		}
		j++;
	}
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_win_param *win_param;

	win_param = param;
	win_param->center_x = ((double)x - win_param->size_x / 2) / win_param->zoom +  win_param->center_x;
	win_param->center_y = ((double)y - win_param->size_y / 2) / win_param->zoom +  win_param->center_y;
	if (button == 4 && win_param->zoom < 2147483647)
		win_param->zoom *= 2;
	if (button == 5 && win_param->zoom > 100)
		win_param->zoom /= 2;
	draw_mandelbrot(win_param);
	return (0);
}


int	main(void)
{
	void	*mlx_p;
	void	*mlx_w;
	t_win_param win_param;

	mlx_p = mlx_init();
	mlx_w = mlx_new_window(mlx_p, 500, 500, "TEST");
	win_param.mlx_p = mlx_p;
	win_param.mlx_w = mlx_w;
	win_param.size_x = 500;
	win_param.size_y = 500;
	win_param.center_x = 0;
	win_param.center_y = 0;
	win_param.zoom = 250;
	draw_mandelbrot(&win_param);
	mlx_mouse_hook(mlx_w, mouse_hook, &win_param);
	mlx_loop(mlx_p);
	mlx_destroy_window(mlx_p, mlx_w);
}

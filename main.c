/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:25:29 by aoizel            #+#    #+#             */
/*   Updated: 2023/12/01 14:44:31 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

void	wrong_parameters_message(void)
{
	ft_printf("Could not use given parameters.\n");
	ft_printf("Use fractol m [size_x size_y] for Mandelbrot.\n");
	ft_printf("Use fractol j Real Imaginary [size_x size_y] for Julia\n");
	ft_printf("Use fractol b [size_x size_y] for Burning Ship\n");
	ft_printf("Use fractol t [size_x size_y] for Tricorn\n");
	ft_printf("size_x and size_y are optional positive integer parameters.");
}

void	init_win_param_size(int argc, char **argv, t_win_param *win_param)
{
	win_param->fractal = argv[1][0];
	win_param->size_x = 1000;
	win_param->size_y = 1000;
	win_param->max_iter = MAX_ITER;
	if (win_param->fractal == 'm' || win_param->fractal == 'b'
		|| win_param->fractal == 't')
	{
		if (argc >= 4)
		{
			win_param->size_x = ft_atoi(argv[2]);
			win_param->size_y = ft_atoi(argv[3]);
		}
	}
	if (win_param->fractal == 'j')
	{
		win_param->j_real_param = ft_atof(argv[2]);
		win_param->j_im_param = ft_atof(argv[3]);
		if (argc >= 6)
		{
			win_param->size_x = ft_atoi(argv[4]);
			win_param->size_y = ft_atoi(argv[5]);
		}
	}
	win_param->color_range = color_range(win_param->max_iter);
}

int	init_win_param(int argc, char **argv, t_win_param *win_param)
{
	if (argc == 1
		|| (argv[1][0] != 'j' && argv[1][0] != 'm'
		&& argv[1][0] != 'b' && argv[1][0] != 't')
		|| (argv[1][0] == 'j' && argc < 4))
	{
		wrong_parameters_message();
		win_param->fractal = 'N';
		return (-1);
	}
	init_win_param_size(argc, argv, win_param);
	win_param->center_x = 0;
	win_param->center_y = 0;
	win_param->zoom = 250;
	if (win_param->size_x <= 0 || win_param->size_y <= 0)
	{
		wrong_parameters_message();
		win_param->fractal = 'N';
		return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	void		*mlx_p;
	void		*mlx_w;
	t_win_param	win_param;

	mlx_p = mlx_init();
	if (!mlx_p)
		return (-1);
	mlx_w = mlx_new_window(mlx_p, win_param.size_x, win_param.size_y,
			"fractol");
	if (!mlx_w)
	{
		mlx_destroy_display(mlx_p);
		return (-1);
	}
	init_win_param(argc, argv, &win_param);
	if (win_param.fractal == 'N')
		return (-1);
	win_param.mlx_p = mlx_p;
	win_param.mlx_w = mlx_w;
	draw(&win_param);
	mlx_mouse_hook(mlx_w, mouse_hook, &win_param);
	mlx_key_hook(mlx_w, key_hook, &win_param);
	mlx_hook(win_param.mlx_w, 17, 0, win_close, &win_param);
	mlx_loop(mlx_p);
}

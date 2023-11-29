/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:26:02 by aoizel            #+#    #+#             */
/*   Updated: 2023/11/29 15:44:58 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "minilibx-linux/mlx.h"
# include <math.h>

typedef struct s_win_param
{
	void				*mlx_p;
	void 				*mlx_w;
	double				center_x;
	double				center_y;
	unsigned int		size_x;
	unsigned int		size_y;
	unsigned int		zoom;

}	t_win_param;

#endif

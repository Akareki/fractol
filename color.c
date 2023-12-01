/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:25:22 by aoizel            #+#    #+#             */
/*   Updated: 2023/12/01 14:06:45 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fractol.h"

unsigned int	*color_range(int max)
{
	unsigned int	*color_range;
	int				i;

	i = 0;
	color_range = ft_calloc(max, sizeof(int));
	while (i < max)
	{
		color_range[i] = GRAD_S + ((GRAD_E % 256 - GRAD_S % 256) * i / max
				+ 256
				* (((GRAD_E / 256) % 256 - (GRAD_S / 256) % 256) * i / max)
				+ 256 * 256
				* ((GRAD_E / (256 * 256) - GRAD_S / (256 * 256)) * i / max));
		i++;
	}
	color_range[max - 1] = 0;
	return (color_range);
}

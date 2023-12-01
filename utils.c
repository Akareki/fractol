/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoizel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:19:20 by aoizel            #+#    #+#             */
/*   Updated: 2023/12/01 14:07:09 by aoizel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *nptr)
{
	double	num;
	int		sign;
	size_t	i;
	size_t	ten_pow;

	num = 0;
	sign = 1;
	i = 0;
	ten_pow = 10;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ' )
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i++] == '-')
		sign = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = 10 * num + nptr[i++] - '0';
	if (nptr[i] == '.')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num + ((double)(nptr[i++] - '0') / ten_pow);
		ten_pow *= 10;
	}
	return (sign * num);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:19:41 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/07 14:19:41 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	ft_pow(double num, t_i64 exponent)
{
	double	temp;

	if (exponent == 0)
		return (1);
	if (exponent % 2 == 0)
	{
		temp = ft_pow(num, exponent / 2);
		return (temp * temp);
	}
	return num * ft_pow(num, exponent - 1);
}

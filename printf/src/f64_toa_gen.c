/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f64_toa_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:27:30 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/07 14:27:30 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"
#include "ft_math.h"
#include "ft_string.h"

#include <stdio.h>

static long long	f64_toa_round(double f)
{
	long long	i_value;
	double		decimal;

	i_value = (long long)f;
	decimal = f - i_value;
	if (decimal > 0.1)
		return (i_value + 1);
	if (decimal < -0.1)
		return (i_value - 1);
	return (i_value);
}

char				*f64_toa_gen(double num, size_t b, const char *fmt)
{
	int			exponential;
	long long	significand;
	char		*numeric_string = NULL;
	char		*iter;

	exponential = f64_expd(num);
	significand = f64_toa_round(num * ft_pow(b, exponential));

	printf("num: %f\n", num);
	printf("exponential: %d\n", exponential);
	printf("significand: %lld\n", significand);
	printf("significand (no round): %f\n", (num * ft_pow(10, 19)));

	numeric_string = ft_strnew(exponential + ft_count_digits((int)num, b) + (size_t)(num < 0 ? 2 : 1));
	iter = numeric_string + exponential + ft_count_digits((int)num, b) + (num < 0 ? 1 : 0);
	if (num < 0)
		*numeric_string = fmt[0];
	while (significand || exponential >= 0)
	{
		*iter = fmt[(significand % b) + 1];
		significand /= b;
		exponential--;
		iter--;
		if (exponential == 0)
		{
			*iter = fmt[b + 1];
			iter--;
		}
	}
	return (numeric_string);
}

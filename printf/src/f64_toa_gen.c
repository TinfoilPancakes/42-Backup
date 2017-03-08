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

/*
**	Works, but barely -- When passing a float variable, the implicit
**	cast causes the multiplication by power to fail...
**	Why? I have no fucking clue.
*/

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

char				*f64_toa_gen(t_f64 num, size_t b, const char *fmt, int p)
{
	int			exp;
	long long	sig;
	char		*n_str;
	char		*iter;

	exp = f64_expd(num);
	if (exp > p)
		exp = p;
	sig = f64_toa_round(num * ft_pow(10.0, exp));
	n_str = ft_strnew(exp + ft_count_digits((int)num, b) + (size_t)
		(num < 0 ? 2 : 1));
	iter = n_str + exp + ft_count_digits((int)num, b) + (num < 0 ? 1 : 0);
	if (num < 0)
		*n_str = fmt[0];
	while (sig || exp >= 0)
	{
		*iter = fmt[(sig % b) + 1];
		sig /= b;
		exp--;
		iter--;
		if (exp == 0)
		{
			*iter = fmt[b + 1];
			iter--;
		}
	}
	return (n_str);
}

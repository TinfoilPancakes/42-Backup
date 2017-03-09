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

char				*f64_toa_gen(t_f64 num, size_t b, const char *fmt, int p)
{
	size_t		n_str_size;
	long long	sig;
	char		*n_str;
	char		*iter;

	sig = (long long)(num * ft_pow(b, p));
	n_str_size = p + ft_count_digits((long)num, b) + ((num < 0) ? 2 : 1);
	n_str = ft_strnew(n_str_size);
	iter = n_str + n_str_size - 1;
	if (num < 0)
		*n_str = fmt[0];
	while (sig || p >= 0)
	{
		*iter = fmt[(sig % b) + 1];
		sig /= b;
		p--;
		iter--;
		if (p == 0)
		{
			*iter = fmt[b + 1];
			iter--;
		}
	}
	return (n_str);
}

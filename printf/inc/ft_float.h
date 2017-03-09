/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 11:25:19 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/09 11:25:19 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include <string.h>
# include "ft_typedefs.h"

/*
**	Math... you know for stuff... and things.
*/

# define LOG_10_2 0.30102999566

/*
**	Macros for converting floats to doubles.
*/

# define FTOA_D(x, p) f64_toa_gen(x, 10, "-0123456789.", p)
# define FTOA_XS(x, p) f64_toa_gen(x, 16, "-0123456789abcdef.", p)
# define FTOA_XL(x, p) f64_toa_gen(x, 16, "-0123456789ABCDEF.", p)
# define FTOA_O(x, p) f64_toa_gen(x, 8, "-012345678.", p)
# define FTOA_B(x, p) f64_toa_gen(x, 2, "-01.", p)

union	u_f64bits
{
	t_f64	f;
	struct
	{
		t_ui64	m : 52;
		t_ui32	e : 11;
		t_ui32	s : 1;
	}		p;
};

typedef	union u_f64bits t_f64bits;

int		f64_expb(t_f64 f);

int		f64_expd(t_f64 f);

char	*f64_toa_gen(double num, size_t b, const char *fmt, int p);

#endif

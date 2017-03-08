//
// Created by Prateek Patil on 1/13/17.
//

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include <string.h>
# include "ft_typedefs.h"

# define LOG_10_2 0.30102999566

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

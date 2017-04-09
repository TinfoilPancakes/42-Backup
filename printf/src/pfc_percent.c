#include "ft_printf.h"

char	*pfc_percent(t_pf_arg arg, va_list ap)
{
	char	*rv;

	(void)arg;
	(void)ap;
	rv = ft_strnew(1);
	rv[0] = '%';
	return (rv);
}

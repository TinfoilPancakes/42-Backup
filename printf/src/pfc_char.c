#include <wchar.h>
#include "ft_printf.h"

static char	*pfc_wchar(va_list ap);

char	*pfc_char(t_pf_arg arg, va_list ap)
{
	char	*rv;

	if (arg.len.l)
		return (pfc_wchar(ap));
	rv = (char *)ft_memalloc(1);
	*rv = (unsigned char)va_arg(ap, int);
	return (rv);
}

#include "ft_printf.h"

const t_pfc_method pfc_dispatch[] = {
	NULL,
	&pfc_percent,
	&pfc_char
};

char	*pf_convert_arg(t_pf_arg arg, va_list ap)
{
	const char *conversions;
	size_t		conversion_id;

	conversions = PF_CONVERSIONS;
	conversion_id = ft_strchr(conversions, arg.conversion) - conversions;
	conversion_id = PF_CONV_INDEX[conversion_id];
	return (pfc_dispatch[conversion_id](arg, ap));
}

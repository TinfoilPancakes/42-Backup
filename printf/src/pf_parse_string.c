#include "ft_printf.h"

/*
**	Assumes passing in non '%' character.
*/

t_pf_argument	pf_parse_string(char **fmt_iter)
{
	t_pf_argument	arg;
	char			*i;

	arg = pf_argument();
	i = pff_parse_format(*fmt_iter, &arg);
	i = pff_parse_min_width(i, &arg);
	i = pff_parse_precision(i, &arg);
	i = pff_parse_length(i, &arg);
	i = pff_parse_conversion(i, &arg);
	*fmt_iter = i;
	return (arg);
}

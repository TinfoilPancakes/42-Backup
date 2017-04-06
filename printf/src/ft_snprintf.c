#include "ft_printf.h"
#include "ft_vector.h"
#include "ft_output.h"

int	ft_snprintf(char *fmt, char **buffer, va_list ap)
{
	t_vector		buff;
	t_pf_argument	current_arg;

	buff = ft_vec_new(sizeof(char));
	while (*fmt)
	{
		if (*fmt == '%')
		{
			current_arg = pf_parse_string(&fmt);
			if (pf_convert_args(&buff, &current_arg, ap) > 0)
				return (-1);
		}
		else
			ft_vec_push(&buff, fmt);
		fmt++;
	}
	*buffer = buff.data;
	return (0);
}

#include "ft_printf.h"
#include "ft_vector.h"

/*
**	
*/

int	ft_snprintf(char *fmt, char **s, va_list ap)
{
	t_vector		buff;
	t_pf_arg		current_arg;
	char			*temp_str;
	int				rv;

	buff = ft_vec_new(sizeof(char));
	while (*fmt)
	{
		if (*fmt != '%')
			ft_vec_push(&buff, fmt);
		else 
		{
			// Parse Argument.
			// Convert
			// Format
			// Push to buffer.
		}
		fmt++;
	}
	*s = (char *)buff.data;
	return (buff.count);
}

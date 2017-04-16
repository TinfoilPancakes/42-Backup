/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 09:53:26 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/16 09:54:53 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_vector.h"

int	ft_vsprintf(char *fmt, char **s, va_list ap)
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

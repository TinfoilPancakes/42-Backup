/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 01:56:52 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/16 09:57:04 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Assumes passing in non '%' character.
*/

t_pf_arg	pf_parse_arg(char **fmt_iter, va_list ap, int *bytes_out)
{
	t_pf_arg	arg;
	char		*i;

	arg = pf_arg();
	arg.bytes_out = bytes_out;
	i = pfp_format(*fmt_iter, &arg);
	i = pfp_min_width(i, &arg);
	i = pfp_precision(i, &arg);
	i = pfp_length(i, &arg);
	i = pfp_conversion(i, &arg);
	if (arg.mw.star)
		arg.mw.min_width = va_arg(ap, int);
	if (arg.prec.star)
		arg.prec.precision = va_arg(ap, int);
	*fmt_iter = i;
	return (arg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 02:32:02 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/16 11:42:01 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const t_pfc_method g_pfc_dispatch[] = {
	NULL,
	&pfc_percent,
	&pfc_char,
	&pfc_string,
};

char	*pf_convert_arg(t_pf_arg arg, va_list ap)
{
	const char *conversions;
	size_t		conversion_id;

	conversions = PF_CONVERSIONS;
	conversion_id = ft_strchr(conversions, arg.conversion) - conversions;
	conversion_id = PF_CONV_INDEX[conversion_id];
	return (g_pfc_dispatch[conversion_id](arg, ap));
}

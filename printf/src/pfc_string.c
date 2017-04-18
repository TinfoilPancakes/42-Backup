/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfc_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 14:56:57 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/16 15:14:53 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"

static char	*pfc_wchar_string(va_list ap)
{
	wchar_t	*p;

	p = va_arg(ap, wchar_t *);
	return (ft_watoa_utf8(p));
}

char		*pfc_string(t_pf_arg arg, va_list ap)
{
	char *rv;

	rv = NULL;
	if (arg.len.l)
		rv = pfc_wchar_string(ap);
	else
		rv = va_arg(ap, char *);
	return (rv);
}

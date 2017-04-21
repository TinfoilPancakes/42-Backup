/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfc_signed_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:38:33 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/19 15:02:22 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "ft_printf.h"

static char	*pfc_si_default(va_list ap, int p)
{
	return (ft_itoa_generic(va_arg(ap, int), 10, p, "-0123456789"));
}

static char *pfc_si_l(va_list ap, int p)
{
	return (ft_itoa_generic(va_arg(ap, long), 10, p, "-0123456789"));
}

static char *pfc_si_lljzt(va_list ap, int p)
{
	return (ft_itoa_generic(va_arg(ap, long long), 10, p, "-0123456789"));
}

char		*pfc_signed_int(t_pf_arg arg, va_list ap)
{
	char	*rv;

	if (!arg.prec.exists)
		arg.prec.precision = 1;
	if (arg.len.l == 1)
		rv = pfc_si_l(ap, arg.prec.precision);
	else if (arg.len.l == 2 || arg.len.j || arg.len.z || arg.len.t)
		rv = pfc_si_lljzt(ap, arg.prec.precision);
	else
		rv = pfc_si_default(ap, arg.prec.precision);
	return (rv);
}

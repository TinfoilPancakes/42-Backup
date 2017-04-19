/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfc_signed_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 13:38:33 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/18 16:56:06 by ppatil           ###   ########.fr       */
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

static char *pfc_si_h(va_list ap, int p)
{
	return (ft_itoa_generic((short)va_arg(ap, int), 10, p, "-0123456789"));
}

static char *pfc_si_hh(va_list ap, int p)
{
	return (ft_itoa_generic((char)va_arg(ap, int), 10, p, "-0123456789"));
}

static char *pfc_si_j(va_list ap, int p)
{
	return (ft_itoa_generic(va_arg(ap, intmax_t), 10, p, "-0123456789"));
}

static char *pfc_si_z(va_list ap, int p)
{
	return (ft_itoa_generic(va_arg(ap, size_t), 10, p, "-0123456789"));
}

static char *pfc_si_t(va_list ap, int p)
{
	return (ft_itoa_generic(va_arg(ap, ptrdiff_t), 10, p, "-0123456789"));
}

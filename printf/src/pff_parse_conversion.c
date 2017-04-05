/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pff_parse_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:40:06 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/13 12:40:06 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdint.h>

// Check Norme Compliance.

static void	pfc_arg_size_c(t_pf_argument *arg)
{
	if (arg->len.l == 1)
		arg->arg_length = sizeof(wchar_t[2]);
	else
		arg->arg_length = sizeof(unsigned char);
}

static void	pfc_arg_size_s(t_pf_argument *arg)
{
	if (arg->len.l == 1)
		arg->arg_length = sizeof(wchar_t *);
	else
		arg->arg_length = sizeof(char *);
}

static void	pfc_arg_size_di(t_pf_argument *arg)
{
	if (arg->len.t)
		arg->arg_length = sizeof(ptrdiff_t);
	else if (arg->len.z)
		arg->arg_length = sizeof(size_t);
	else if (arg->len.j)
		arg->arg_length = sizeof(intmax_t);
	else if (arg->len.l == 2)
		arg->arg_length = sizeof(long long);
	else if (arg->len.l == 1)
		arg->arg_length = sizeof(long);
	else if (arg->len.h == 2)
		arg->arg_length = sizeof(signed char);
	else if (arg->len.h == 1)
		arg->arg_length = sizeof(short);
	else
		arg->arg_length = sizeof(int);
}

static void	pfc_arg_size_oxu(t_pf_argument *arg)
{
	if (arg->len.t)
		arg->arg_length = sizeof(ptrdiff_t);
	else if (arg->len.z)
		arg->arg_length = sizeof(size_t);
	else if (arg->len.j)
		arg->arg_length = sizeof(uintmax_t);
	else if (arg->len.l == 2)
		arg->arg_length = sizeof(unsigned long long);
	else if (arg->len.l == 1)
		arg->arg_length = sizeof(unsigned long);
	else if (arg->len.h == 2)
		arg->arg_length = sizeof(unsigned char);
	else if (arg->len.h == 1)
		arg->arg_length = sizeof(unsigned short);
	else
		arg->arg_length = sizeof(unsigned int);
}

static void	(*pfc_ptrs[])(t_pf_argument *a) = {
	&pfc_arg_size_c,
	&pfc_arg_size_s,
	&pfc_arg_size_di,
	&pfc_arg_size_oxu
};

static char	pfc_indexes[] = "c\0s\1d\2i\2o\3x\3X\3u\3";

char		*pff_parse_conversion(char *fmt, t_pf_argument *arg)
{
	char	*iter;

	iter = pfc_indexes;
	while (iter - pfc_indexes < (long)sizeof(pfc_indexes))
	{
		if (*iter == *fmt)
			pfc_ptrs[(t_byte)*(iter + 1)](arg);
		iter += 2;
	}
	arg->conversion = *fmt;
	fmt++;
	return (fmt);
}

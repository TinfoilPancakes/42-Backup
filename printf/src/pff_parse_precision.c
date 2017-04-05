/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pff_prase_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:12:46 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/13 12:12:46 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pff_parse_precision(char *fmt, t_pf_argument *arg)
{
	if (*fmt != '.')
		return (fmt);
	fmt++;
	arg->prec.exists = 1;
	if (*fmt == '*')
	{
		arg->prec.star = 1;
		fmt++;
	}
	else if (ft_isdigit(*fmt) || *fmt == '-')
	{
		if (*fmt == '-')
		{
			arg->prec.exists = 0;
			fmt++;
		}
		else
			arg->prec.precision = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
	}
	else
		arg->prec.precision = 0;
	return (fmt);
}

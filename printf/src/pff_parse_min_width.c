/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pff_parse_min_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:05:00 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/13 12:05:00 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pff_parse_min_width(char *fmt, t_pf_argument *arg)
{
	if (*fmt == '*')
	{
		arg->mw.exists = 1;
		arg->mw.star = 1;
		fmt++;
	}
	else if (ft_isdigit(*fmt))
	{
		arg->mw.exists = 1;
		arg->mw.min_width = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
	}
	return (fmt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pff_parse_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:20:54 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/13 12:20:54 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pff_parse_length(char *fmt, t_pf_argument *arg)
{
	while (ft_strchr("hljztL", *fmt))
	{
		if (*fmt == 'h')
			arg->len.h++;
		if (*fmt == 'l')
			arg->len.l++;
		if (*fmt == 'j')
			arg->len.j = 1;
		if (*fmt == 'z')
			arg->len.z = 1;
		if (*fmt == 't')
			arg->len.z = 1;
		if (*fmt == 'L')
			arg->len.L = 1;
		fmt++;
	}
	return (fmt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfp_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:56:38 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/13 11:56:38 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pfp_format(char *fmt, t_pf_arg *arg)
{
	while (ft_strchr("-+#0 ", *fmt))
	{
		if (*fmt == '-')
			arg->fmt.minus = 1;
		else if (*fmt == '+')
			arg->fmt.plus = 1;
		else if (*fmt == ' ')
			arg->fmt.space = 1;
		else if (*fmt == '#')
			arg->fmt.pound = 1;
		else if (*fmt == '0')
			arg->fmt.zero = 1;
		fmt++;
	}
	return (fmt);
}

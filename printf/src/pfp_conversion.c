/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfp_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 12:40:06 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/13 12:40:06 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pfp_conversion(char *fmt, t_pf_arg *arg)
{
	if (ft_strchr(PF_CONVERSIONS, *fmt) && *fmt)
	{
		arg->conversion = *fmt;
		fmt++;
	}
	return (fmt);
}

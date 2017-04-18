/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoa_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 09:54:30 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/16 14:50:11 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

void	ft_wctoa_utf8(wint_t wc, char **rv)
{
	char	out[] = "\0\0\0\0\0";

	if (wc <= 0x7F)
		out[0] = (char)wc;
	else if (wc <= 0x7FF)
	{
		out[0] = (wc >> 6) + 0xC0;
		out[1] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0xFFFF)
	{
		out[0] = (wc >> 12) + 0xE0;
		out[1] = (wc >> 6) + 0x80;
		out[2] = (wc & 0x3F) + 0x80;
	}
	else {
		out[0] = (wc >> 18) + 0xF0;
		out[1] = (wc >> 12) + 0x80;
		out[2] = (wc >> 6) + 0x80;
		out[3] = (wc & 0x3F) + 0x80;
	}
	*rv = ft_strnew(ft_strlen(out));
	ft_memcpy(*rv, out, 4);
}
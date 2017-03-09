/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:37:30 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/09 12:37:30 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



t_pffb	pf_parse_flags(const char *fmt)
{
	t_pffb	block;

	block.start = fmt;
	return (block);
}

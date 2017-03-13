/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 11:54:51 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/13 11:54:51 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_memory.h"

t_pf_argument	pf_argument(void)
{
	t_pf_argument arg;

	ft_bzero(&arg, sizeof(t_pf_argument));
	return (arg);
}

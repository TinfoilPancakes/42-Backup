/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:42:31 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/07 14:42:31 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_output.h"
#include <stdio.h>

// Huh...

int main(void)
{
	wchar_t test = 20153;
	char *rv;
	ft_wctoa_utf8(test, &rv);
	ft_putstr(rv);
	ft_memdel((void **)&rv);
	ft_putstr("\n");
	return 0;
}

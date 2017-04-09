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
#include <stdio.h>

int main(void)
{
	t_pf_arg arg_test;
	char	test_str[] = "-#4.2luEND";
	char	*iter = test_str;
	arg_test = pf_parse_arg(&iter, NULL);
	printf("conversion specifier : %c\n", arg_test.conversion);
	printf("actual arg_size : %lu\n", sizeof(unsigned long));
	printf("remaining str : %1.23s\n", iter);
	return 0;
}

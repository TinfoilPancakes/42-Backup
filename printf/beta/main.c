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
	t_pf_argument arg_test;
	char	test_str[] = "-#4.2luEND";
	char	*iter = test_str;
	arg_test = pf_parse_string(&iter);
	printf("argument_size : %lu\n", arg_test.arg_length);
	printf("actual arg_size : %lu\n", sizeof(unsigned long));
	printf("remaining str : %s\n", iter);
	return 0;
}

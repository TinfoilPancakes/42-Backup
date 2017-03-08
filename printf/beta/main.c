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

#include "ft_float.h"
#include <stdio.h>

#define TEST_FLOAT 0.00021

int main(void)
{
	float test_thing = 0.000210;

	printf("std printf: %f\n", test_thing);
	printf("ft  printf: %s\n", f64_toa_gen(test_thing, 10, "-0123456789."));
	return 0;
}

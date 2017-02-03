/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:14:54 by ppatil            #+#    #+#             */
/*   Updated: 2017/01/27 12:47:28 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "img_buffer.h"
# include "ft_typedefs.h"

void	fract_plot(t_img_buff *img, void *a, t_color f(void *a, t_vec2f p));

t_vec2f	complex_mult(t_vec2f a, t_vec2f b)
{
	t_vec2f r;

	r.x = a.x * b.x - a.y * b.y;
	r.y = a.x * b.y + a.y * b.x;
	return (r);
}

float	length_sqaured(t_vec2f v)
{
	return (v.x * v.x + v.y * v.y);
}

float	julia_loop(t_vec2f p, t_vec2f x, unsigned int iter_count)
{
	unsigned int	i;

	i = 0;
	while (i < iter_count)
	{
		if (length_sqaured(p) >= 4.0)
			return ((float)i / (float)iter_count);
		p = VEC2F_ADD(x, complex_mult(p, p));
		i++;
	}
	return 1.0;
}

t_color	test_colorize(void *args, t_vec2f pos)
{
	t_img_buff	*buff;
	float		val;

	buff = (t_img_buff *)args;
	pos = VEC2F_DIV(pos, vec2f_init(buff->width, buff->height));
	val = julia_loop(pos, vec2f_init(0.5, 0.4), 64);
	return (color_init(0, 64 * val, 255 * val));
}

#endif

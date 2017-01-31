/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_line_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:54:04 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/14 12:54:04 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_buffer.h"

/*
**	This wrapper function shouldn't be accessed directly.
*/

static void	img_buff_plot_wrapper(t_pixel p, t_color *c, void *args)
{
	void		**a;
	t_vec3f		*col;
	t_img_buff	*b;

	a = (void **)args;
	col = (t_vec3f *)a[2];
	col->x += ((t_vec3f *)a[1])->x;
	col->y += ((t_vec3f *)a[1])->y;
	col->z += ((t_vec3f *)a[1])->z;
	p.c = *c;
	b = (t_img_buff *)a[0];
	*c = color_init(col->x, col->y, col->z);
	if (p.x < b->width && p.y < b->height && p.x >= 0 && p.y >= 0)
		img_buff_plot((t_img_buff *)a[0], p);
}

void		img_line_draw(t_img_buff *buff, t_pixel p0, t_pixel p1)
{
	t_vec3f	color_delta;
	t_vec3f	color;
	t_vec2f	p[2];
	float	dist;
	void	*args[3];

	p[0] = vec2f_init(p0.x, p0.y);
	p[1] = vec2f_init(p1.x, p1.y);
	dist = VEC2F_LENGTH(VEC2F_SUB(p[1], p[0]));
	if (!dist)
		return ;
	color_delta.x = (p1.c.c.r - p0.c.c.r) / dist;
	color_delta.y = (p1.c.c.g - p0.c.c.g) / dist;
	color_delta.z = (p1.c.c.b - p0.c.c.b) / dist;
	color.x = p0.c.c.r;
	color.y = p0.c.c.g;
	color.z = p0.c.c.b;
	args[0] = buff;
	args[1] = &color_delta;
	args[2] = &color;
	pixel_line_draw(p0, p1, img_buff_plot_wrapper, args);
}

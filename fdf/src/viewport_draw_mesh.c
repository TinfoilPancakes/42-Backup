/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_draw_mesh.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:42:37 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/21 14:42:37 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

static t_pixel	pixel_make(t_color c, t_viewport *vp, t_vec2f s_pos)
{
	t_pixel	new_pixel;
	int		scale;

	new_pixel.c = c;
	if (vp->img.width < vp->img.height)
		scale = vp->img.width / 2;
	else
		scale = vp->img.height / 2;
	new_pixel.x = vp->img.width / 2 + scale * s_pos.x;
	new_pixel.y = vp->img.height / 2 + scale * s_pos.y;
	return (new_pixel);
}

void			viewport_draw_mesh(
	t_viewport *vp,
	t_mesh *m,
	t_color cf(t_vec3f a, t_vec2f b))
{
	t_vector	points;
	t_vec2f		x;
	t_vec2f		y;
	t_pixel		p[2];
	int			*e_iter;

	e_iter = (int *)m->edges.data;
	points = viewport_mesh_plot(vp, m);
	while (e_iter != (int *)m->edges.end)
	{
		x = *(t_vec2f *)ft_vec_at(&points, e_iter[0]);
		y = *(t_vec2f *)ft_vec_at(&points, e_iter[1]);
		p[0] = pixel_make(
		cf(*(t_vec3f *)ft_vec_at(&m->vertecies, e_iter[0]), x), vp, x);
		p[1] = pixel_make(
		cf(*(t_vec3f *)ft_vec_at(&m->vertecies, e_iter[1]), y), vp, y);
		if (p[1].x < vp->img.width && p[1].y < vp->img.height &&
			p[0].x < vp->img.width && p[0].y < vp->img.height)
			img_line_draw(&vp->img, p[0], p[1]);
		e_iter += 2;
	}
	ft_vec_del(&points);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_mesh_plot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:42:02 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/21 14:42:02 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

t_vector	viewport_mesh_plot(t_viewport *vp, t_mesh *m)
{
	t_vector	new_vertecies;
	t_vector	plotted_points;
	t_vec2f		p;
	t_vec3f		*iter;

	new_vertecies = mesh_vert_transform(m);
	plotted_points = ft_vec_new(sizeof(t_vec2f));
	iter = (t_vec3f *)new_vertecies.data;
	while (iter != new_vertecies.end)
	{
		p = vec3f_perspective_proj(*iter, vp->f_length);
		ft_vec_push(&plotted_points, &p);
		iter++;
	}
	ft_vec_del(&new_vertecies);
	return (plotted_points);
}

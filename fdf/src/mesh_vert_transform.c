/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_vert_transform.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:06:09 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/17 20:06:09 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

t_vector	mesh_vert_transform(t_mesh *m)
{
	t_vector	transformed;
	t_vec3f		*iter;

	transformed = ft_vec_copy(&m->vertecies);
	iter = (t_vec3f *)transformed.data;
	while (iter != transformed.end)
	{
		*iter = VEC3F_ADD((*iter), m->offset);
		*iter = VEC3F_SCALE((*iter), m->scale);
		*iter = mat4f_vec_mult(*iter, mat4f_rotation_euler(m->rotation));
		*iter = VEC3F_ADD((*iter), m->pos);
		iter++;
	}
	return (transformed);
}

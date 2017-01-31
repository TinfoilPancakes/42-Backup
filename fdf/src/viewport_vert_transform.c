/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_vert_transform.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:41:11 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/21 14:41:11 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

void	viewport_vert_transform(t_viewport *vp, t_vector *vv)
{
	t_vec3f	*v_ptr;

	v_ptr = (t_vec3f *)vv->data;
	while (v_ptr != vv->end)
	{
		*v_ptr = VEC3F_SUB((*v_ptr), vp->c_pos);
		*v_ptr = mat4f_vec_mult(*v_ptr, mat4f_rotation_euler(vp->c_angles));
		v_ptr++;
	}
}

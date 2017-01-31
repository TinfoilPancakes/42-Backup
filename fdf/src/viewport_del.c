/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:39:34 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/21 14:39:34 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

void	viewport_del(t_viewport *vp)
{
	t_mesh *m_ptr;

	m_ptr = (t_mesh *)vp->meshes.data;
	while (m_ptr != vp->meshes.end)
	{
		mesh_del(m_ptr);
		m_ptr++;
	}
	ft_vec_del(&vp->meshes);
	img_buff_destroy(&vp->img);
	vp->c_pos = vec3f();
	vp->c_angles = vec3f();
	vp->f_length = 0;
}

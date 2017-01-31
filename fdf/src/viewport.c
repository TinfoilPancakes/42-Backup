/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:58:06 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/21 11:58:06 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

t_viewport	viewport(void *mlx_ptr, int w, int h)
{
	t_viewport	vp;

	vp.img = img_buff(mlx_ptr, w, h);
	vp.meshes = ft_vec_new(sizeof(t_mesh));
	vp.c_pos = vec3f();
	vp.c_angles = vec3f();
	vp.f_length = 1.0;
	return (vp);
}

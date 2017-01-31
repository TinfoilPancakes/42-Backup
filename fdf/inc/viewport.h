/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:06:43 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/17 20:06:43 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

# include "img_buffer.h"
# include "mesh.h"

struct		s_viewport
{
	t_img_buff	img;
	t_vector	meshes;
	t_vec3f		c_pos;
	t_vec3f		c_angles;
	float		f_length;
};

typedef	struct s_viewport	t_viewport;

t_viewport	viewport(void *mlx_ptr, int w, int h);

void		viewport_del(t_viewport *vp);

void		viewport_vert_transform(t_viewport *vp, t_vector *vv);

t_vector	viewport_mesh_plot(t_viewport *vp, t_mesh *m);

void		viewport_draw_mesh(
	t_viewport *vp,
	t_mesh *m,
	t_color colorize(t_vec3f, t_vec2f));

#endif

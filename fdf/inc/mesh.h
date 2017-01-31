/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:14:58 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/15 17:14:58 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESH_H
# define MESH_H

# include "lib3d.h"
# include "libft.h"

/*
**	Rotations are in (x: Yaw, y: Pitch, z: Roll)
*/

struct		s_mesh
{
	t_vector	vertecies;
	t_vector	edges;
	t_vec3f		offset;
	t_vec3f		pos;
	t_vec3f		rotation;
	float		scale;
};

typedef	struct s_mesh	t_mesh;

t_vector	mesh_vert_transform(t_mesh *m);

t_mesh		mesh(void);

void		mesh_del(t_mesh *m);

#endif

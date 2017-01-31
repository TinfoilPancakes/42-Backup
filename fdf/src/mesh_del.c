/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:55:56 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/21 11:55:56 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

void	mesh_del(t_mesh *m)
{
	ft_vec_del(&m->vertecies);
	ft_vec_del(&m->edges);
	m->offset = vec3f();
	m->pos = vec3f();
	m->rotation = vec3f();
	m->scale = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:05:11 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/17 20:05:11 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mesh.h"

t_mesh	mesh(void)
{
	t_mesh	m;

	m.vertecies = ft_vec_new(sizeof(t_vec3f));
	m.edges = ft_vec_new(sizeof(int));
	m.offset = vec3f();
	m.pos = vec3f();
	m.rotation = vec3f();
	m.scale = 1.0;
	return (m);
}

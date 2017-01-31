/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:11:53 by ppatil            #+#    #+#             */
/*   Updated: 2016/12/04 16:11:53 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_loop(void *params)
{
	t_byte		*keys;
	t_mesh		*m;

	keys = (t_byte *)((void **)params)[3];
	m = (t_mesh *)((t_viewport *)((void **)params)[2])->meshes.data;
	if (keys[0])
		m->rotation.z += M_PI / 256;
	if (keys[1])
		m->rotation.z -= M_PI / 256;
	if (keys[2])
		m->rotation.y += M_PI / 256;
	if (keys[3])
		m->rotation.y -= M_PI / 256;
	if (keys[4])
		exit(EXIT_SUCCESS);
	if (keys[5])
		m->rotation.x -= M_PI / 256;
	if (keys[6])
		m->rotation.x += M_PI / 256;
	if (keys[7])
		m->pos.z -= 1;
	if (keys[8])
		m->pos.z += 1;
	fdf_redraw(params);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_redraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:10:20 by ppatil            #+#    #+#             */
/*   Updated: 2016/12/04 16:10:20 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_redraw(void *params)
{
	void		**p;
	void		*mlx_ptr;
	void		*win_ptr;
	t_viewport	*vp;

	p = (void **)params;
	mlx_ptr = p[0];
	win_ptr = p[1];
	vp = (t_viewport *)p[2];
	img_buff_clear(&vp->img);
	viewport_draw_mesh(vp, (t_mesh *)vp->meshes.data, fdf_colorize);
	mlx_put_image_to_window(mlx_ptr, win_ptr, vp->img.img_ptr, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_expose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:12:27 by ppatil            #+#    #+#             */
/*   Updated: 2016/12/04 16:12:27 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_expose(void *params)
{
	void		**p;
	void		*mlx;
	void		*win;
	t_byte		*keys;

	p = (void **)params;
	keys = (t_byte *)p[3];
	win = p[1];
	mlx = p[0];
	ft_bzero(keys, 8);
	mlx_hook(win, 2, 0, fdf_key_down, params);
	mlx_hook(win, 3, 0, fdf_key_up, params);
	mlx_loop_hook(mlx, fdf_loop, params);
	fdf_redraw(params);
	return (1);
}

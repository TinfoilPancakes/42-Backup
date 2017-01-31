/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_plot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:51:00 by ppatil            #+#    #+#             */
/*   Updated: 2017/01/27 12:51:00 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Should iterate over the image correctly. Need to make sure doesn't go out of bounds.
*/

void	fract_plot(t_img_buff *img, void *a, t_color f(void *a, t_vec2f p))
{
	t_vec2f	p;
	int		*iter;

	p = vec2f_init(0, 0);
	iter = (int *)img->data_addr;
	while (p.y < img->height)
	{
		*iter = f(a, p).val;
		p.x++;
		iter++;
		if (p.x >= img->width)
			p = vec2f_init(0, p.y + 1);
	}
}

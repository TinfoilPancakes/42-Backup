/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:50:00 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/14 12:50:00 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_buffer.h"

t_img_buff	img_buff(void *mlx_ptr, int width, int height)
{
	t_img_buff	buff;

	buff.mlx_ptr = mlx_ptr;
	buff.height = height;
	buff.width = width;
	buff.img_ptr = mlx_new_image(mlx_ptr, width, height);
	buff.data_addr = mlx_get_data_addr(
		buff.img_ptr,
		&buff.color_depth,
		&buff.line_len,
		&buff.endian);
	return (buff);
}

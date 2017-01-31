/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_buff_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:51:42 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/14 12:51:42 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_buffer.h"

void	img_buff_destroy(t_img_buff *buff)
{
	mlx_destroy_image(buff->mlx_ptr, buff->img_ptr);
	buff->mlx_ptr = NULL;
	buff->img_ptr = NULL;
	buff->data_addr = NULL;
	buff->line_len = 0;
	buff->color_depth = 0;
	buff->endian = 0;
	buff->height = 0;
	buff->width = 0;
}

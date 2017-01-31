/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_buff_plot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:52:35 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/14 12:52:35 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_buffer.h"

void	img_buff_plot(t_img_buff *b, t_pixel p)
{
	*(int *)(b->data_addr + p.y * b->line_len + p.x * sizeof(int)) = p.c.val;
}

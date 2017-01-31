/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_buff_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:40:58 by ppatil            #+#    #+#             */
/*   Updated: 2016/12/02 22:40:58 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_buffer.h"
#include "ft_memory.h"

void	img_buff_clear(t_img_buff *buff)
{
	ft_bzero(buff->data_addr, buff->line_len * buff->height);
}

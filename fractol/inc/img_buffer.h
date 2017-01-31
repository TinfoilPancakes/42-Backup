/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_buffer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:16:22 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/14 10:16:22 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_BUFFER_H
# define IMG_BUFFER_H

# include "mlx.h"
# include "lib3d.h"

# ifndef NULL
#  define NULL 0
# endif

struct		s_img_buff
{
	void	*mlx_ptr;
	void	*img_ptr;
	char	*data_addr;
	int		height;
	int		width;
	int		line_len;
	int		color_depth;
	int		endian;
};

typedef	struct s_img_buff	t_img_buff;

t_img_buff	img_buff(void *mlx_ptr, int width, int height);

void		img_buff_destroy(t_img_buff	*buff);

void		img_buff_plot(t_img_buff *buff, t_pixel	p);

void		img_line_draw(t_img_buff *buff, t_pixel p0, t_pixel p1);

void		img_buff_clear(t_img_buff *buff);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:14:54 by ppatil            #+#    #+#             */
/*   Updated: 2017/01/27 12:47:28 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "img_buffer.h"
# include "ft_typedefs.h"

void	fract_plot(t_img_buff *img, void *a, t_color f(void *a, t_vec2f p));

#endif

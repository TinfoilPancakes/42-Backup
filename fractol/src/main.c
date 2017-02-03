/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:21:07 by ppatil            #+#    #+#             */
/*   Updated: 2017/01/25 13:21:10 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	http://glslsandbox.com/e#38076.28 - GPU based julia fractol.
*/

#include "mlx_wrapper.h"
#include "libft.h"
#include "lib3d.h"
#include "fractol.h"



int	main(void)
{
	t_img_buff	buffer;
	t_mlxw		wrap;
	t_vec2f		complex_pos;
	t_vec2f		viewport_delta;
	void		*temp;

	wrap = mlxw();
	mlxw_window_create(&wrap, 1280, 800, "fractol");
	buffer = img_buff(wrap.mlx_ptr, 1280, 800);
	temp = &buffer;
	ft_vec_push(&wrap.argument_list, &temp);
	complex_pos = vec2f_init(0.5, 0.5);
	temp = &complex_pos;
	ft_vec_push(&wrap.argument_list, &temp);
	viewport_delta = vec2f_init(0, 0);
	temp = &viewport_delta;
	ft_vec_push(&wrap.argument_list, &temp);
	mlxw_init_events(&wrap);
	mlxw_launch(&wrap);
	return 0;
}

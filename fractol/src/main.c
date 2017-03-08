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

#include <time.h>
#include <stdio.h>

static t_vec2f	complex_mult(t_vec2f a, t_vec2f b)
{
	t_vec2f r;

	r.x = a.x * b.x - a.y * b.y;
	r.y = a.x * b.y + a.y * b.x;
	return (r);
}

static float	length_sqaured(t_vec2f v)
{
	return (v.x * v.x + v.y * v.y);
}

static float	julia_loop(t_vec2f p, t_vec2f x, const unsigned int iter_count)
{
	unsigned int	i;

	i = 0;
	while (i < iter_count)
	{
		if (length_sqaured(p) >= 4.0)
			return (i / (float)iter_count);
		p = VEC2F_ADD(x, complex_mult(p, p));
		i++;
	}
	return 1.0;
}

static t_color	fractol_frag(void *args, t_vec2f pos)
{
	void	**a;
	float	val;
	t_vec2f	scale;
	t_vec2f dimensions;

	a = args;
	dimensions = *(t_vec2f *)a[2];
	scale = *(t_vec2f *)a[1];
	pos = VEC2F_SUB(pos, dimensions);
	pos = VEC2F_MULT(pos, scale);
	val = julia_loop(pos, (*(t_vec2f *)a[0]), 64);
	return (color_init(64 * val, 32 * val, 255 * val));
}

static void	change_cpos(t_mlxw *t)
{
	t_vec2f		*c_pos;
	t_img_buff	*img;

	img = *(void **)ft_vec_at(&t->argument_list, 0);
	c_pos = *(void **)ft_vec_at(&t->argument_list, 1);
	*c_pos = vec2f_init(t->mouse_state.x, t->mouse_state.y);
	*c_pos = VEC2F_SUB((*c_pos), vec2f_init(img->width / 2, img->height / 2));
	*c_pos = VEC2F_DIV((*c_pos), vec2f_init(img->width, img->height));
}

static void fractol(t_mlxw *t)
{
	t_img_buff	*img;
	t_vec2f		dimensions;
	t_vec2f		scale;
	void		*args[3];

	img = *(void **)ft_vec_at(&t->argument_list, 0);
	dimensions = vec2f_init(img->width / 2, img->height / 2);
	scale.x = (img->width > img->height) ? img->height : img->width;
	scale.x *= 0.2;
	scale.x = 1 / scale.x;
	scale = vec2f_init(scale.x, scale.x);
	args[0] = *(void **)ft_vec_at(&t->argument_list, 1);
	args[1] = &scale;
	args[2] = &dimensions;
	fract_plot(img, args, fractol_frag);
}

static void	buff_display(t_mlxw *thing)
{
	t_img_buff	*img;

	img = *(void **)ft_vec_at(&thing->argument_list, 0);
	mlx_put_image_to_window(thing->mlx_ptr, thing->mlx_window_ptr, img->img_ptr, 0, 0);
}

static void	debug_info(t_mlxw *t)
{
	t_vec2f	*cpos;
	char str[256];

	cpos = *(void **)ft_vec_at(&t->argument_list, 1);
	sprintf(str, "cpos: (%f, %f)\n", cpos->x, cpos->y);
	mlx_string_put(t->mlx_ptr, t->mlx_window_ptr, 0, 0, color_init(255, 255, 32).val, str);
	sprintf(str, "Mouse_Pos: (%d, %d)\n", (int)t->mouse_state.x, (int)t->mouse_state.y);
	mlx_string_put(t->mlx_ptr, t->mlx_window_ptr, 0, 25, color_init(255, 25, 255).val, str);
}

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
	complex_pos = vec2f_init(0, 0);
	temp = &complex_pos;
	ft_vec_push(&wrap.argument_list, &temp);
	viewport_delta = vec2f_init(0, 0);
	temp = &viewport_delta;
	ft_vec_push(&wrap.argument_list, &temp);
	temp = &change_cpos;
	ft_vec_push(&wrap.mlx_op_queue, &temp);
	temp = &fractol;
	ft_vec_push(&wrap.mlx_op_queue, &temp);
	temp = &buff_display;
	ft_vec_push(&wrap.mlx_op_queue, &temp);
	temp = &debug_info;
	ft_vec_push(&wrap.mlx_op_queue, &temp);
	mlxw_init_events(&wrap);
	mlxw_launch(&wrap);
	return 0;
}

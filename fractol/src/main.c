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

#include "mlx.h"
#include "libft.h"
#include "lib3d.h"
#include "fractol.h"

t_color	test_colorize(void *args, t_vec2f pos)
{
	(void)args;
	(void)pos;
	return (color_init(255, 128, 128));
}

int	main(void)
{
	t_img_buff	image;
	void	*mlx_context;
	void	*mlx_window;

	mlx_context = mlx_init();
	mlx_window = mlx_new_window(mlx_context, 1280, 800, "fractol ~");
	image = img_buff(mlx_context, 1280, 800);
	fract_plot(&image, NULL, test_colorize);
	mlx_put_image_to_window(mlx_context, mlx_window, image.img_ptr, 0, 0);
	mlx_do_key_autorepeatoff(mlx_context);
	mlx_loop(mlx_context);
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:43:58 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/12 13:43:58 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "lib3d.h"
#include "libft.h"
#include "img_buffer.h"
#include "viewport.h"

void	fdf_initialize(const char *filename, int height, int width)
{
	void		*window;
	void		*params[5];
	t_byte		keys[10];
	t_mesh		file_mesh;
	t_viewport	vp;

	params[0] = mlx_init();
	vp = viewport(params[0], width, height);
	vp.f_length = 1.0;
	window = mlx_new_window(params[0], vp.img.width, vp.img.height, "fdf");
	file_mesh = fdf_from_file(filename);
	params[1] = window;
	params[2] = &vp;
	params[3] = keys;
	ft_vec_push(&vp.meshes, &file_mesh);
	mlx_do_key_autorepeatoff(params[0]);
	mlx_expose_hook(window, fdf_expose, params);
	mlx_loop(params[0]);
}

int		main(int ac, char **av)
{
	int h;
	int w;

	if (ac > 1)
	{
		if (ac == 4)
		{
			w = ft_atoi(av[2]);
			h = ft_atoi(av[3]);
			if (h > 0 && w > 0)
				fdf_initialize(av[1], h, w);
			else
			{
				ft_putstr_fd("Error: Must have valid window dimensions.\n", 2);
				return (-1);
			}
		}
		else
			fdf_initialize(av[1], 720, 1280);
	}
	ft_putstr_fd("Error: Please specify filename.\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:30:05 by ppatil            #+#    #+#             */
/*   Updated: 2017/02/01 09:30:05 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

t_mlxw	mlxw(void)
{
	t_mlxw	mlx_object;

	ft_memset(mlx_object.keystates, 0, MLX_KEYSTATE_SIZE);
	mlx_object.mouse_state = vec3f();
	mlx_object.mlx_ptr = mlx_init();
	mlx_object.mlx_window_ptr = NULL;
	mlx_object.argument_list = ft_vec_new(sizeof(void *));
	mlx_object.mlx_op_queue = ft_vec_new(sizeof(t_mlx_op));
	return (mlx_object);
}

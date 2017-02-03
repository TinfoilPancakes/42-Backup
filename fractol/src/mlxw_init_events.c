/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_init_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:57:55 by ppatil            #+#    #+#             */
/*   Updated: 2017/02/01 13:57:55 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include "ft_output.h"

#include <stdio.h>

static int	mlx_keydown_capture(int keycode, void *params)
{
	t_mlxw	*mlxw;

	mlxw = (t_mlxw *)params;
	mlxw->keystates[keycode] = 1;
	return (0);
}

static int	mlx_keyup_capture(int keycode, void *params)
{
	t_mlxw	*mlxw;

	mlxw = (t_mlxw *)params;
	mlxw->keystates[keycode] = 0;
	return (0);
}

int	mlx_wrapper_loop(void *params)
{
	t_mlxw		*mlxw;
	t_mlx_op	*iter;
	int			debug;

	mlxw = (t_mlxw *)params;
	iter = mlxw->mlx_op_queue.data;
	debug = 1;
	printf("Ops: %lu\n", mlxw->mlx_op_queue.count);
	while (iter < (t_mlx_op *)mlxw->mlx_op_queue.end)
	{
		printf("Running op # %d\n", debug);
		(*iter)(mlxw);
		iter++;
		debug++;
		printf("Done.\n");
	}
	return (0);
}

static int	mlx_expose_callback(t_mlxw *mlxw)
{
	mlx_hook(mlxw->mlx_window_ptr, 2, 0, mlx_keydown_capture, mlxw);
	mlx_hook(mlxw->mlx_window_ptr, 3, 0, mlx_keyup_capture, mlxw);
	mlx_loop_hook(mlxw->mlx_ptr, mlx_wrapper_loop, mlxw);
	return (1);
}

void	mlxw_init_events(t_mlxw *mlxw)
{
	if (mlxw->mlx_window_ptr == NULL)
	{
		ft_putstr("ERROR: Cannot initialize mlx events without first creating window.\n");
		return ;
	}
	mlx_do_key_autorepeatoff(mlxw->mlx_ptr);
	mlx_expose_hook(mlxw->mlx_window_ptr, mlx_expose_callback, mlxw);
}

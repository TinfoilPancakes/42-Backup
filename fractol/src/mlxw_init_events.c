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

static int	mlx_mouse_pos_capture(int x, int y, void *params)
{
	t_mlxw	*mlxw;

	mlxw = (t_mlxw *)params;
	mlxw->mouse_state.x = x;
	mlxw->mouse_state.y = y;
	return (0);
}

static int	mlx_mouse_click_capture(int button, int x, int y, void *params)
{
	t_mlxw	*mlxw;

	mlxw = (t_mlxw *)params;
	(void)x;
	(void)y;
	mlxw->mouse_state.z = button;
	return (0);
}

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

	mlxw = (t_mlxw *)params;
	iter = mlxw->mlx_op_queue.data;
	while (iter < (t_mlx_op *)mlxw->mlx_op_queue.end)
	{
		(*iter)(mlxw);
		iter++;
	}
	return (0);
}

static int	mlx_expose_callback(t_mlxw *mlxw)
{
	mlx_hook(mlxw->mlx_window_ptr, 2, 0, mlx_keydown_capture, mlxw);
	mlx_hook(mlxw->mlx_window_ptr, 3, 0, mlx_keyup_capture, mlxw);
	mlx_hook(mlxw->mlx_window_ptr, 6, 0, mlx_mouse_pos_capture, mlxw);
	mlx_mouse_hook(mlxw->mlx_window_ptr, mlx_mouse_click_capture, mlxw);
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

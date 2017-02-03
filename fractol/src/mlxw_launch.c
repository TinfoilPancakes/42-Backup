/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_launch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:33:42 by ppatil            #+#    #+#             */
/*   Updated: 2017/02/01 18:33:42 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"
#include "ft_output.h"

void	mlxw_launch(t_mlxw *mlxw)
{
	if (mlxw->mlx_window_ptr == NULL)
	{
		ft_putstr("ERROR: Window not created, call mlxw_window_create(...)\n");
		return ;
	}
	mlx_loop(mlxw->mlx_ptr);
}

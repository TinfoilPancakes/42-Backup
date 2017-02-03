/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:57:52 by ppatil            #+#    #+#             */
/*   Updated: 2017/02/01 09:57:52 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	mlxw_destroy(t_mlxw *mlxw)
{
	if (mlxw->mlx_window_ptr != NULL)
		mlx_destroy_window(mlxw->mlx_ptr, mlxw->mlx_window_ptr);
}

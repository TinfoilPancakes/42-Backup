/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw_window_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:42:30 by ppatil            #+#    #+#             */
/*   Updated: 2017/02/01 09:42:30 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_wrapper.h"

void	mlxw_window_create(t_mlxw *mlxw, int w, int h, const char *n)
{
	mlxw->mlx_window_ptr = mlx_new_window(mlxw->mlx_ptr, w, h, (char *)n);
}

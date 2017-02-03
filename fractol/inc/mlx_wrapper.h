/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_wrapper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 08:54:37 by ppatil            #+#    #+#             */
/*   Updated: 2017/02/01 08:54:37 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Forgive me for I have over-engineered. I don't know whether to continue
**	working on this wrapper...
**
**	Functions are prefixed with "mlxw_" for length reasons becuase fucking
**	norme.
*/

#ifndef MLX_WRAPPER_H
# define MLX_WRAPPER_H

# include "mlx.h"
# include "ft_memory.h"
# include "ft_vector.h"
# include "img_buffer.h"

/*
**	Currently have to keep track of what arguments are where.
**	They are cast to void* at the moment and I cannot figure a better way to
**	store them.
*/

# define MLX_KEYSTATE_SIZE 256

struct	s_mlx_wrapper
{
	void		*mlx_ptr;
	void		*mlx_window_ptr;
	char		keystates[MLX_KEYSTATE_SIZE];
	t_vector	argument_list;
	t_vector	mlx_op_queue;
};

typedef	struct s_mlx_wrapper t_mlxw;

typedef	void (*t_mlx_op)(t_mlxw *mlxw);

/*
**	Reminder to self: typedefs using function pointers are wierd.
**	t_mlx_op is the name of the typedef.
*/

t_mlxw	mlxw(void);

void	mlxw_window_create(t_mlxw *mlxw, int w, int h, const char *n);

void	mlxw_destroy(t_mlxw *mlxw);

void	mlxw_init_events(t_mlxw *mlxw);

void	mlxw_launch(t_mlxw *mlxw);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:32:47 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/23 17:32:47 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "lib3d.h"
# include "viewport.h"
# include "mesh.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

t_mesh	fdf_from_file(const char *filename);

t_color	fdf_colorize(t_vec3f v, t_vec2f p);

void	fdf_redraw(void *params);

int		fdf_key_down(int keycode, void *params);

int		fdf_key_up(int keycode, void *params);

int		fdf_loop(void *params);

int		fdf_expose(void *params);

#endif

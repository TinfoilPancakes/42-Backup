/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:10:46 by ppatil            #+#    #+#             */
/*   Updated: 2016/12/04 16:10:46 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key_down(int keycode, void *params)
{
	void	**p;
	t_byte	*keys;

	p = (void **)params;
	keys = (t_byte *)p[3];
	if (keycode == 123)
		keys[0] = 1;
	if (keycode == 124)
		keys[1] = 1;
	if (keycode == 126)
		keys[2] = 1;
	if (keycode == 125)
		keys[3] = 1;
	if (keycode == 53)
		keys[4] = 1;
	if (keycode == 0x0C)
		keys[5] = 1;
	if (keycode == 0x0E)
		keys[6] = 1;
	if (keycode == 0x0D)
		keys[7] = 1;
	if (keycode == 0x01)
		keys[8] = 1;
	return (0);
}

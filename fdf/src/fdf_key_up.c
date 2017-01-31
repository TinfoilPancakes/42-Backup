/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:11:08 by ppatil            #+#    #+#             */
/*   Updated: 2016/12/04 16:11:08 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key_up(int keycode, void *params)
{
	void	**p;
	t_byte	*keys;

	p = (void **)params;
	keys = (t_byte *)p[3];
	if (keycode == 123)
		keys[0] = 0;
	if (keycode == 124)
		keys[1] = 0;
	if (keycode == 126)
		keys[2] = 0;
	if (keycode == 125)
		keys[3] = 0;
	if (keycode == 53)
		keys[4] = 0;
	if (keycode == 0x0C)
		keys[5] = 0;
	if (keycode == 0x0E)
		keys[6] = 0;
	if (keycode == 0x0D)
		keys[7] = 0;
	if (keycode == 0x01)
		keys[8] = 0;
	return (0);
}

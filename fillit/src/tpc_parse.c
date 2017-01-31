/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpc_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 11:25:22 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/12 11:25:22 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_grid.h"
#include "tetris_piece.h"

t_tpc	tpc_parse(char *s)
{
	t_pointc	rl;
	t_tpc		np;
	char		*i;

	np = INL_TPC_INIT;
	rl = INL_POINTC_INIT;
	i = np.os;
	while (i < (np.os + 8) && *s)
	{
		if (*s == '\n' && i != np.os)
		{
			rl.x -= 5;
			rl.y++;
		}
		if (*s++ == '#')
		{
			i[0] = rl.x;
			i[1] = rl.y;
			rl = INL_POINTC_INIT;
			i += 2;
		}
		if (i != np.os)
			rl.x++;
	}
	return (np);
}

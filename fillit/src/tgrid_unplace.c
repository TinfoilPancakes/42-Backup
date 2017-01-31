/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgrid_unplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 22:19:36 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/12 22:19:36 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_grid.h"

void	tgrid_unplace(t_tgrid *tg, t_pointc guess, t_tpc pc, char id)
{
	char	*s;

	s = pc.os;
	while (s - pc.os < 8)
	{
		guess.x += s[0];
		guess.y += s[1];
		if (guess.x < 0 || guess.x >= tg->size || guess.y >= tg->size
			|| *INL_TGRID_P(tg, guess) != id)
			return ;
		*INL_TGRID_P(tg, guess) = '.';
		s += 2;
	}
}

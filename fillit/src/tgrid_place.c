/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgrid_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 21:57:39 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/12 21:57:39 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_grid.h"

int	tgrid_place(t_tgrid *tg, t_pointc guess, t_tpc pc, char id)
{
	char	*s;

	s = pc.os;
	while (s - pc.os < 8)
	{
		guess.x += s[0];
		guess.y += s[1];
		if (guess.x < 0)
			return (-1);
		if (guess.x >= tg->size)
			return (-2);
		if (guess.y >= tg->size)
			return (-3);
		if (*INL_TGRID_P(tg, guess) != '.')
			return (0);
		*INL_TGRID_P(tg, guess) = id;
		s += 2;
	}
	return (1);
}

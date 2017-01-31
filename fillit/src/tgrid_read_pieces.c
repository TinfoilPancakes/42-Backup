/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgrid_read_pieces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:00:16 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/13 14:00:16 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_grid.h"
#include "libft.h"

void	tgrid_read_pieces(t_tgrid *tg, char *fb, int n)
{
	char	*iter;
	t_tpc	*i;

	tg->pieces = ft_memalloc(sizeof(t_tpc) * n);
	i = tg->pieces;
	tg->n = n;
	tg->gpos = ft_memalloc(sizeof(t_pointc) * tg->n);
	while (*fb)
	{
		iter = fb;
		*i = tpc_parse(iter);
		fb += 21;
		i++;
	}
}

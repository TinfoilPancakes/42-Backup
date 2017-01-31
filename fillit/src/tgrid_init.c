/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgrid_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 15:36:26 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/18 15:36:26 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_grid.h"

t_tgrid	tgrid_init(void)
{
	t_tgrid	g;

	g.pieces = NULL;
	g.gpos = NULL;
	g.buff = NULL;
	g.n = 0;
	g.size = 0;
	return (g);
}

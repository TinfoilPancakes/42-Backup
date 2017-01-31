/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgrid_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:42:52 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/12 17:42:52 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_grid.h"
#include "libft.h"

void	tgrid_resize(t_tgrid *tg, int nsize)
{
	char	*newbuff;

	newbuff = tgrid_buff_init(nsize);
	ft_memdel((void **)&(tg->buff));
	tg->buff = newbuff;
	tg->size = nsize;
}

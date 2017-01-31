/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tgrid_buff_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 18:14:24 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/12 18:14:24 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris_grid.h"
#include "libft.h"

char	*tgrid_buff_init(int size)
{
	char	*iter;
	char	*buff;

	buff = ft_strnew(size * size + size);
	iter = buff;
	if (buff)
	{
		ft_memset(buff, '.', size * size + size);
		while (*iter)
		{
			iter += size;
			*iter = '\n';
			iter++;
		}
	}
	return (buff);
}

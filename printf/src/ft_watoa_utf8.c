/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watoa_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 11:32:49 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/16 14:56:34 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"

char	*ft_watoa_utf8(wchar_t *ws)
{
	t_vector	buff;
	char		*tmp;

	buff = ft_vec_new(sizeof(char));
	while (*ws)
	{
		ft_wctoa_utf8(*ws, &tmp);
		ft_vec_append(&buff, tmp, ft_strlen(tmp));
		ft_memdel((void **)&tmp);
		ws++;
	}
	return (buff.data);
}

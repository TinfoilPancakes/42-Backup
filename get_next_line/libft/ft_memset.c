/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 14:34:47 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/18 16:20:30 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_byte	*s_ptr;
	size_t	*b_ptr;
	size_t	cb;
	t_byte	cc;

	cc = (t_byte)c;
	cb = cc;
	cb |= cb << 8;
	cb |= cb << 16;
	cb |= cb << 32;
	s_ptr = b;
	while (len % 8)
	{
		*s_ptr = cc;
		++s_ptr;
		--len;
	}
	b_ptr = (size_t *)s_ptr;
	while (len)
	{
		*b_ptr = cb;
		++b_ptr;
		len -= 8;
	}
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 08:03:22 by ppatil            #+#    #+#             */
/*   Updated: 2016/09/23 08:03:22 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*iter;

	iter = (char *)s + ft_strlen(s);
	c = (char)c;
	while (iter >= s)
	{
		if (*iter == c)
			return (iter);
		--iter;
	}
	return (NULL);
}

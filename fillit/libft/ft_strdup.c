/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:24:35 by ppatil            #+#    #+#             */
/*   Updated: 2016/09/22 11:24:35 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	byte_count;
	char	*new_string;

	byte_count = ft_strlen(s1);
	new_string = (char *)malloc((byte_count + 1) * sizeof(char));
	if (new_string != NULL)
		return (ft_memmove(new_string, s1, (byte_count + 1) * sizeof(char)));
	return (NULL);
}

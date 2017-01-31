/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:10:41 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/05 11:10:41 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 42

struct		s_fhandle
{
	int			fd;
	char		*pos;
	long long	read;
	char		buff[BUFF_SIZE + 1];
};

typedef	struct s_fhandle	t_fhandle;

int			get_next_line(int fd, char **line);

#endif

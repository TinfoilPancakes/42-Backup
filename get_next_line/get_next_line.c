/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 21:10:51 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/05 21:10:51 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

t_fhandle	*get_handle(t_list *l, int fd)
{
	t_list *i;

	i = l;
	while (i)
	{
		if ((*(t_fhandle **)i->content)->fd == fd)
			return (*(t_fhandle **)i->content);
		i = i->next;
	}
	return (NULL);
}

int			add_handle(t_list **l, int fd)
{
	t_fhandle	*nh;

	if (!l)
		return (-1);
	nh = (t_fhandle *)ft_memalloc(sizeof(t_fhandle));
	nh->fd = fd;
	nh->pos = nh->buff;
	nh->read = read(fd, nh->buff, BUFF_SIZE);
	if (nh->read < 0)
	{
		ft_memdel((void **)&nh);
		return (-1);
	}
	ft_lstadd(l, ft_lstnew(&nh, sizeof(nh)));
	return (1);
}

void		pop_handle(t_list **l, int fd)
{
	t_list	*iter;

	iter = *l;
	while (iter && (*(t_fhandle **)iter->content)->fd != fd)
		iter = iter->next;
	if (!iter)
		return ;
	if (iter == *l)
		*l = iter->next;
	ft_memdel((void **)iter->content);
	ft_memdel(&iter->content);
	ft_memdel((void **)&iter);
}

char		*read_line(t_fhandle *hndl, t_vector *str, char *rval)
{
	if (hndl->pos == hndl->buff + hndl->read)
	{
		hndl->read = read(hndl->fd, hndl->buff, BUFF_SIZE);
		hndl->pos = hndl->buff;
	}
	if (hndl->pos >= hndl->buff + hndl->read)
		return (NULL);
	str = ft_vec_new(sizeof(char));
	while (hndl->pos < hndl->buff + hndl->read && rval)
	{
		if (*(hndl->pos) != '\n')
			ft_vec_append(str, hndl->pos);
		else
			rval = NULL;
		(hndl->pos)++;
		if (hndl->pos == hndl->buff + BUFF_SIZE)
		{
			hndl->read = read(hndl->fd, hndl->buff, BUFF_SIZE);
			hndl->pos = hndl->buff;
		}
	}
	ft_vec_append(str, "\0");
	rval = str->data;
	ft_memdel((void **)&str);
	return (rval);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*active_handles;
	t_fhandle		*hndl;

	if (!line || fd < 0)
		return (-1);
	if (!active_handles)
		if (add_handle(&active_handles, fd) < 0)
			return (-1);
	hndl = get_handle(active_handles, fd);
	if (!hndl)
	{
		if (add_handle(&active_handles, fd) < 0)
			return (-1);
		hndl = get_handle(active_handles, fd);
	}
	*line = read_line(hndl, NULL, (char *)1);
	if (!(*line))
	{
		pop_handle(&active_handles, hndl->fd);
		return (0);
	}
	return (1);
}

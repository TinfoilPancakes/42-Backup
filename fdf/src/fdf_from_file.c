/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_from_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 06:03:10 by ppatil            #+#    #+#             */
/*   Updated: 2016/11/28 06:03:10 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "errno.h"

static void	fdf_add_vertex(t_mesh *m, t_vec3f pos, int width, int index)
{
	int	edge;

	ft_vec_push(&m->vertecies, &pos);
	if (pos.x > 0)
	{
		edge = index;
		ft_vec_push(&m->edges, &edge);
		edge = index - 1;
		ft_vec_push(&m->edges, &edge);
	}
	if (pos.y > 0)
	{
		edge = index;
		ft_vec_push(&m->edges, &edge);
		edge = index - width;
		ft_vec_push(&m->edges, &edge);
	}
}

static void	ugly_ass_shit(t_vec3f os, t_vec3f p)
{
	if (p.x != os.z * os.x)
	{
		ft_putstr_fd("ERR: Invalid line length in file.\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	fdf_parse_file(t_mesh *m, char *s, t_vec3f os, t_vec3f p)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == '\n')
		{
			if (p.y == 0)
				os.z = i;
			ugly_ass_shit(os, p);
			p = vec3f_init(0, p.y + os.y, p.z);
			s++;
		}
		else if (ft_isdigit(*s))
		{
			fdf_add_vertex(m, vec3f_init(p.x, p.y, -8 * ft_atoi(s)), os.z, i);
			p = vec3f_init(p.x + os.x, p.y, p.z);
			while (*s && *s != '\n' && !ft_isspace(*s))
				s++;
			i++;
		}
		else
			s++;
	}
	m->offset = vec3f_init(-os.z * os.x / 2, -p.y / 2, m->offset.z);
}

t_mesh		fdf_from_file(const char *filename)
{
	t_mesh		m;
	t_vector	file_buff;
	char		buff[1024];
	int			fd;
	int			bytes_read;

	m = mesh();
	file_buff = ft_vec_newn(sizeof(char), 1025);
	fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		fd = errno;
		ft_putstr_fd("ERR:[ mesh_from_file ]: ", 2);
		ft_putstr_fd(strerror(fd), 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	while ((bytes_read = read(fd, buff, 1024)))
		ft_vec_append(&file_buff, buff, bytes_read);
	fdf_parse_file(&m, (char *)file_buff.data, vec3f_init(10, 10, 0), vec3f());
	ft_vec_del(&file_buff);
	m.pos.z = fabsf(((m.offset.x > m.offset.y) ? m.offset.x : m.offset.y) * 3);
	return (m);
}

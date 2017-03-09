/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:14:23 by ppatil            #+#    #+#             */
/*   Updated: 2017/03/09 12:14:23 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "ft_string.h"
# include "ft_vector.h"

struct	s_pf_flag
{
	char	*flag_str;
	size_t	count;
};

typedef	struct s_pf_flag	t_pff;

struct	s_pf_fmt_block
{
	char	*start;
	t_pff	behavior;
	t_pff	min_width;
	t_pff	precision;
	t_pff	length;
	t_pff	conversion;
};

typedef	struct s_pf_fmt_block	t_pffb;

t_pff	pf_get_conversion_flag(const char *fmt)
{
	t_pff	flag;

	flag.flag_str = NULL;
	fmt++;
	while (*fmt && !flag.flag_str)
	{
		if (ft_strchr("%sSpdDioOuUxXcCfF", *fmt))
		{
			flag.flag_str = (char *)fmt;
			flag.count = 1;
		}
		fmt++;
	}
	while(ft_strchr("hljz", *(flag.flag_str - 1)))
	{
		flag.flag_str--;
		flag.count++;
	}
	return (flag);
}

#endif

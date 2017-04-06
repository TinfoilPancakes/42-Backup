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

struct	s_pf_format_flags
{
	unsigned int	minus : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	unsigned int	pound : 1;
	unsigned int	zero : 1;
};

typedef	struct s_pf_format_flags t_pff_format;

struct	s_pf_min_width_flag
{
	unsigned int	exists : 1;
	unsigned int	star : 1;
	unsigned int	min_width : 30;
};

typedef	struct s_pf_min_width_flag t_pff_min_width;

struct	s_pf_precision_flag
{
	unsigned int	exists : 1;
	unsigned int	star : 1;
	unsigned int	precision : 30;
};

typedef	struct s_pf_precision_flag	t_pff_precision;

struct	s_pf_length_flag
{
	unsigned int	h : 2;
	unsigned int	l : 2;
	unsigned int	j : 1;
	unsigned int	z : 1;
	unsigned int	t : 1;
	unsigned int	L : 1;
};

typedef	struct s_pf_length_flag t_pff_length;

struct	s_pf_arg_format
{
	t_pff_format	fmt;
	t_pff_min_width	mw;
	t_pff_precision	prec;
	t_pff_length	len;
	char			conversion;
	size_t			arg_length;
	void			*arg;
};

typedef	struct s_pf_arg_format	t_pf_argument;

/*
**	This whole section is just for the conversions... FML
*/

t_pf_argument	pf_argument(void);

t_pf_argument	pf_parse_string(char **fmt_iter);

int				pf_convert_args(t_vector *vec, t_pf_argument *arg, va_list ap);

int				ft_snprintf(char *fmt, char **buffer, va_list ap);

char			*pff_parse_format(char *fmt, t_pf_argument *arg);

char			*pff_parse_min_width(char *fmt, t_pf_argument *arg);

char			*pff_parse_precision(char *fmt, t_pf_argument *arg);

char			*pff_parse_length(char *fmt, t_pf_argument *arg);

char			*pff_parse_conversion(char *fmt, t_pf_argument *arg);



#endif

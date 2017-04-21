/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:14:23 by ppatil            #+#    #+#             */
/*   Updated: 2017/04/19 14:27:26 by ppatil           ###   ########.fr       */
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
	signed int		min_width : 30;
};

typedef	struct s_pf_min_width_flag t_pff_min_width;

struct	s_pf_precision_flag
{
	unsigned int	exists : 1;
	unsigned int	star : 1;
	signed int		precision : 30;
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

/*
**	After several refactors, now stores a pointer to total bytes written.
**	This is to allow for the %n conversion specifier, also to prevent a global.
*/

struct	s_pf_arg_format
{
	t_pff_format	fmt;
	t_pff_min_width	mw;
	t_pff_precision	prec;
	t_pff_length	len;
	char			conversion;
	int				*bytes_out;
};

/*
**	I feel like I should rename t_pf_arg to t_pf_arg...
**	Refactoring is annoying without proper tools.
*/

typedef	struct s_pf_arg_format	t_pf_arg;

/*
**	Parsing...
**	Seems to be working consistently.
** 	- Modified to allow va_list to be passed so I can grab
**	  precision & min width variables if '*' is used.
*/

t_pf_arg	pf_arg(void);

t_pf_arg	pf_parse_arg(char **fmt_iter, va_list ap, int *bytes_out);

char		*pfp_format(char *fmt, t_pf_arg *arg);

char		*pfp_min_width(char *fmt, t_pf_arg *arg);

char		*pfp_precision(char *fmt, t_pf_arg *arg);

char		*pfp_length(char *fmt, t_pf_arg *arg);

char		*pfp_conversion(char *fmt, t_pf_arg *arg);

/*
**	Conversions...
**	char * conversion_function(t_pf_arg , va_list)
**	returns null if error in format.
**	Also the t_pfc_method typdef is really fucking ugly...
*/

typedef	char *(*t_pfc_method)(t_pf_arg arg, va_list ap);

# define PF_CONVERSIONS "%cCsSdDioOxXuUfFpn"
# define PF_CONV_INDEX	"\1\2\2\3\3\4\4\4\5\5\6\6\7\7\x8\x8\x9\xA"

char		*pfc_percent(t_pf_arg arg, va_list ap);

char		*pfc_char(t_pf_arg arg, va_list ap);

char		*pfc_string(t_pf_arg arg, va_list ap);

char		*pf_convert_arg(t_pf_arg arg, va_list ap);

int			ft_vsprintf(char *fmt, char **buffer, va_list ap);

/*
**	Formatting conversion output strings...
*/

#endif

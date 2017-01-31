/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_point.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:28:00 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/17 16:28:00 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_POINT_H
# define TETRIS_POINT_H

struct	s_char_point
{
	char	x;
	char	y;
};

typedef	struct s_char_point	t_pointc;

# define INL_POINTC_INIT (t_pointc) {0 , 0}
# define INL_POINTC_CPY(p) (t_pointc) {p.x, p.y}
# define INL_POINTC_ADD(a, b) (t_pointc) {a.x + b.x, a.y + b.y}
# define INL_POINTC_SUB(a, b) (t_pointc) {a.x - b.x, a.y - b.y}
# define INL_POINTC_MULT(a, b) (t_pointc) {a.x * b.x, a.y * b.y}
# define INL_POINTC_ISEQ(a, b) (a.x == b.x && a.y == b.y)

#endif

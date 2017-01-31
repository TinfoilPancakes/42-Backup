/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_piece.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:51:49 by ppatil            #+#    #+#             */
/*   Updated: 2016/10/11 17:51:49 by ppatil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_PIECE_H
# define TETRIS_PIECE_H

union	u_tpc
{
	unsigned long long	as_ull;
	char				os[8];
};

typedef	union u_tpc	t_tpc;

# define INL_TPC_INIT (t_tpc){0}
# define INL_TPC_EQL(a, b) ((a).as_ull == (b).as_ull)
# define INL_TPC_CPY(s) (t_tpc){s.as_ull}

t_tpc	tpc_parse(char *s);

#endif

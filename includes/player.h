/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_PLAYER_H
# define WOLF3D_PLAYER_H

# include "point.h"
# include <stdlib.h>

# define FRWD 1u << 0u
# define BKWD 1u << 1u
# define LEFT 1u << 2u
# define RGHT 1u << 3u
# define RT_L 1u << 4u
# define RT_R 1u << 5u

# define P_SIZE 0.2
# define P_MOVE_SPEED 0.05
# define P_LOOK_SPEED 0.05

typedef struct	s_player
{
	double		x;
	double		y;
	t_d_pt		plane;
	t_d_pt		dir;
	t_i_pt		map;
	u_int32_t	score;
	u_int64_t	movement;
}				t_player;

void			rotate_player(t_player *p);

#endif

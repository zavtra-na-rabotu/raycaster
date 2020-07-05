/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:43 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:47 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	door_hit(t_game *g, t_player *p, t_r_st *state, double wall_hit)
{
	t_door	*door;
	double	left_side;
	double	right_side;

	wall_hit -= (int)wall_hit;
	door = find_door(g->doors, g->doors_num, p->map.x, p->map.y);
	if (!door)
		return (0);
	state->door = *door;
	left_side = door->moving / 2.0;
	right_side = 1.0 - left_side;
	return ((wall_hit <= left_side) || (wall_hit >= right_side));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "door.h"
#include "wolf3d.h"

int		collision(t_game *g, int x, int y)
{
	t_door *door;

	if (g->map[x][y].type == TYPE_WALL ||
		g->map[x][y].type == TYPE_THIN_WALL ||
		g->map[x][y].type == TYPE_SPRITE_CLSN)
		return (1);
	if (g->map[x][y].type == TYPE_DOOR)
	{
		door = find_door(g->doors, g->doors_num, x, y);
		if (!door)
			return (0);
		if (door->state & ~OPENED)
			return (1);
	}
	return (0);
}

int		can_move(t_game *g, double x, double y)
{
	int x_plus;
	int y_plus;
	int x_minus;
	int y_minus;

	x_plus = (int)(x + P_SIZE);
	y_plus = (int)(y + P_SIZE);
	x_minus = (int)(x - P_SIZE);
	y_minus = (int)(y - P_SIZE);
	if (x_plus < 0 || y_plus < 0
						|| x_plus >= g->map_dim.x || y_plus >= g->map_dim.y)
		return (0);
	if (x_minus < 0 || y_minus < 0
						|| x_minus >= g->map_dim.x || y_minus >= g->map_dim.y)
		return (0);
	if (collision(g, x_plus, y_plus))
		return (0);
	if (collision(g, x_plus, y_minus))
		return (0);
	if (collision(g, x_minus, y_plus))
		return (0);
	if (collision(g, x_minus, y_minus))
		return (0);
	return (1);
}

void	collect_sprite(t_game *g)
{
	t_d_pt	xy_max;
	t_d_pt	xy_min;
	int		i;

	xy_max = d_pt(g->player->x + P_SIZE, g->player->y + P_SIZE);
	xy_min = d_pt(g->player->x - P_SIZE, g->player->y - P_SIZE);
	i = 0;
	while (i < g->sprt_num)
	{
		if (g->sprites[i].coords.x <= xy_max.x
		&& g->sprites[i].coords.y <= xy_max.y
		&& g->sprites[i].coords.x >= xy_min.x
		&& g->sprites[i].coords.y >= xy_min.y
		&& !g->sprites[i].collected)
			break ;
		i++;
	}
	if (i < g->sprt_num)
	{
		g->sprites[i].collected = 1;
		g->map[(int)g->sprites[i].coords.x][(int)g->sprites[i].coords.y].type =
																	TYPE_EMPTY;
		if (g->player->score + G_VALUE <= SCORE_MAX)
			g->player->score += G_VALUE;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "door.h"

void	interaction(t_game *g)
{
	int	x;
	int	y;

	x = floor(g->player->x + g->player->dir.x);
	y = floor(g->player->y + g->player->dir.y);
	if (g->map[x][y].type == TYPE_DOOR)
		open_close_door(g->doors, g->doors_num, x, y);
}

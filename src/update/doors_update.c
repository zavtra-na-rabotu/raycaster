/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:11 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:15 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "door.h"

static void	update_door(t_door *door)
{
	if (door->state & OPENING)
		door->moving -= DOOR_SLIDE;
	else if (door->state & CLOSING)
		door->moving += DOOR_SLIDE;
	if (door->moving >= 1.)
	{
		door->moving = 1;
		door->state = 0;
		door->state = CLOSED;
	}
	else if (door->moving <= 0.)
	{
		door->moving = 0;
		door->state = 0;
		door->state = OPENED;
	}
}

void		update_doors(t_game *g)
{
	int i;

	i = 0;
	while (i < g->doors_num)
	{
		update_door(&g->doors[i]);
		i++;
	}
}

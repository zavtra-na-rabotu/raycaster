/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "door.h"

static void	create_door(t_door **doors, int x, int y, int i)
{
	t_door door;

	door.state = 0;
	door.state |= CLOSED;
	door.moving = 1;
	door.x = x;
	door.y = y;
	(*doors)[i] = door;
}

static int	count_doors(t_map_tile **map, t_i_pt map_dim)
{
	int x;
	int y;
	int num;

	num = 0;
	y = 0;
	while (y < map_dim.y)
	{
		x = 0;
		while (x < map_dim.x)
		{
			if (map[x][y].type == TYPE_DOOR)
				num++;
			x++;
		}
		y++;
	}
	return (num);
}

int			find_doors(t_map_tile **m, t_door **doors, int *num, t_i_pt map_dim)
{
	int x;
	int y;
	int i;

	*num = count_doors(m, map_dim);
	*doors = malloc(sizeof(t_door) * *num);
	if (!*doors)
		return (ERR);
	i = 0;
	y = 0;
	while (y < map_dim.y)
	{
		x = 0;
		while (x < map_dim.x)
		{
			if (m[x][y].type == TYPE_DOOR)
				create_door(doors, x, y, i++);
			x++;
		}
		y++;
	}
	return (OK);
}

t_door		*find_door(t_door *doors, int doors_num, int x, int y)
{
	int		i;

	i = 0;
	while (i < doors_num)
	{
		if (doors[i].x == x && doors[i].y == y)
			return (&doors[i]);
		i++;
	}
	return (NULL);
}

void		open_close_door(t_door *doors, int doors_num, int x, int y)
{
	t_door *door;

	door = find_door(doors, doors_num, x, y);
	if (!door)
		return ;
	if (door->state & OPENED)
	{
		door->state = 0;
		door->state |= CLOSING;
	}
	else if (door->state & CLOSED)
	{
		door->state = 0;
		door->state |= OPENING;
	}
	else if (door->state & CLOSING)
	{
		door->state = 0;
		door->state |= OPENING;
	}
	else if (door->state & OPENING)
	{
		door->state = 0;
		door->state |= CLOSING;
	}
}

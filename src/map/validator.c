/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:14 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:15 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

int		check_tile_consistency(t_map_tile tile)
{
	if (tile.type == TYPE_WALL)
	{
		return (tile.wall_n && tile.wall_e && tile.wall_s && tile.wall_w);
	}
	else if (tile.type == TYPE_EMPTY || tile.type == TYPE_DOOR)
	{
		return (tile.ceil && tile.floor);
	}
	return (0);
}

int		check_sprite_consistency(t_sprite *sprite, t_i_pt dims)
{
	return ((sprite->type == TYPE_SPRITE_DCRT
											|| sprite->type == TYPE_SPRITE_CLSN
											|| sprite->type == TYPE_SPRITE_ENMY
											|| sprite->type == TYPE_SPRITE_PKBL)
		&& sprite->coords.x < dims.x && sprite->coords.y < dims.y
		&& sprite->txtr > 0);
}

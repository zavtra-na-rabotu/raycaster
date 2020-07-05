/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:03 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:05 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	mouse_move_handler(t_game *game, SDL_Event *e)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot;

	old_dir_x = game->player->dir.x;
	old_plane_x = game->player->plane.x;
	rot = (double)-e->motion.xrel * MOUSE_SENS;
	game->player->dir.x = game->player->dir.x * cos(rot)
							- game->player->dir.y * sin(rot);
	game->player->dir.y = old_dir_x * sin(rot)
							+ game->player->dir.y * cos(rot);
	game->player->plane.x = game->player->plane.x * cos(rot)
							- game->player->plane.y * sin(rot);
	game->player->plane.y = old_plane_x * sin(rot)
							+ game->player->plane.y * cos(rot);
}

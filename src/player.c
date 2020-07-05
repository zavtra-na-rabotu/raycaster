/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "door.h"
#include "collision.h"

void	move_lr(t_player *p, t_game *g)
{
	if (p->movement & LEFT)
	{
		if (can_move(g, p->x + -p->dir.y * P_MOVE_SPEED, p->y))
			p->x += -p->dir.y * P_MOVE_SPEED;
		if (can_move(g, p->x, p->y + p->dir.x * P_MOVE_SPEED))
			p->y += p->dir.x * P_MOVE_SPEED;
	}
}

void	rotate_player(t_player *p)
{
	double old_dir_x;
	double old_plane_x;
	double rotation_speed;

	rotation_speed = 0;
	if (p->movement & RT_L)
		rotation_speed = P_LOOK_SPEED;
	if (p->movement & RT_R)
		rotation_speed = -P_LOOK_SPEED;
	old_dir_x = p->dir.x;
	old_plane_x = p->plane.x;
	p->dir.x = p->dir.x * cos(rotation_speed)
											- p->dir.y * sin(rotation_speed);
	p->dir.y = old_dir_x * sin(rotation_speed)
											+ p->dir.y * cos(rotation_speed);
	p->plane.x = p->plane.x * cos(rotation_speed)
											- p->plane.y * sin(rotation_speed);
	p->plane.y = old_plane_x * sin(rotation_speed)
											+ p->plane.y * cos(rotation_speed);
}

void	move_player(t_player *p, t_game *g)
{
	move_lr(p, g);
	if (p->movement & RGHT)
	{
		if (can_move(g, p->x - -p->dir.y * P_MOVE_SPEED, p->y))
			p->x -= -p->dir.y * P_MOVE_SPEED;
		if (can_move(g, p->x, p->y - p->dir.x * P_MOVE_SPEED))
			p->y -= p->dir.x * P_MOVE_SPEED;
	}
	if (p->movement & FRWD)
	{
		if (can_move(g, p->x + p->dir.x * P_MOVE_SPEED, p->y))
			p->x += p->dir.x * P_MOVE_SPEED;
		if (can_move(g, p->x, p->y + p->dir.y * P_MOVE_SPEED))
			p->y += p->dir.y * P_MOVE_SPEED;
	}
	if (p->movement & BKWD)
	{
		if (can_move(g, p->x - p->dir.x * P_MOVE_SPEED, p->y))
			p->x -= p->dir.x * P_MOVE_SPEED;
		if (can_move(g, p->x, p->y - p->dir.y * P_MOVE_SPEED))
			p->y -= p->dir.y * P_MOVE_SPEED;
	}
	if (g->map[(int)g->player->x][(int)g->player->y].type == TYPE_SPRITE_PKBL)
		collect_sprite(g);
}

void	check_player_position(t_game *game)
{
	if (game->player->x < 0)
		game->player->x = 0;
	else if (game->player->x > game->map_dim.x * TILE_SIZE)
		game->player->x = game->map_dim.x * TILE_SIZE;
	if (game->player->y < 0)
		game->player->y = 0;
	else if (game->player->y > game->map_dim.y * TILE_SIZE)
		game->player->y = game->map_dim.y * TILE_SIZE;
}

void	init_player(t_game *game, t_player *p)
{
	p->x = 1.5;
	p->y = 1.5;
	p->movement = 0;
	p->plane.x = 0;
	p->plane.y = 0.66;
	p->dir.x = -1;
	p->dir.y = 0;
	p->score = 0;
	game->player = p;
}

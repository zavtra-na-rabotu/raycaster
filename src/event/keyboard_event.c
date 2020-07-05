/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:03 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:06 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_down_handler(t_game *game, SDL_Event *e)
{
	if (e->key.keysym.scancode == SDL_SCANCODE_LEFT)
		game->player->movement |= RT_L;
	else if (e->key.keysym.scancode == SDL_SCANCODE_RIGHT)
		game->player->movement |= RT_R;
	else if (e->key.keysym.scancode == SDL_SCANCODE_A)
		game->player->movement |= LEFT;
	else if (e->key.keysym.scancode == SDL_SCANCODE_D)
		game->player->movement |= RGHT;
	else if (e->key.keysym.scancode == SDL_SCANCODE_S)
		game->player->movement |= BKWD;
	else if (e->key.keysym.scancode == SDL_SCANCODE_W)
		game->player->movement |= FRWD;
	else if (e->key.keysym.scancode == SDL_SCANCODE_UP)
		game->player->movement |= FRWD;
	else if (e->key.keysym.scancode == SDL_SCANCODE_DOWN)
		game->player->movement |= BKWD;
	else if (e->key.keysym.scancode == SDL_SCANCODE_E)
		interaction(game);
}

void	key_up_handler(t_game *game, SDL_Event *e)
{
	if (e->key.keysym.scancode == SDL_SCANCODE_LEFT)
		game->player->movement &= ~(RT_L);
	else if (e->key.keysym.scancode == SDL_SCANCODE_RIGHT)
		game->player->movement &= ~(RT_R);
	else if (e->key.keysym.scancode == SDL_SCANCODE_A)
		game->player->movement &= ~(LEFT);
	else if (e->key.keysym.scancode == SDL_SCANCODE_D)
		game->player->movement &= ~(RGHT);
	else if (e->key.keysym.scancode == SDL_SCANCODE_S)
		game->player->movement &= ~(BKWD);
	else if (e->key.keysym.scancode == SDL_SCANCODE_W)
		game->player->movement &= ~(FRWD);
	else if (e->key.keysym.scancode == SDL_SCANCODE_UP)
		game->player->movement &= ~(FRWD);
	else if (e->key.keysym.scancode == SDL_SCANCODE_DOWN)
		game->player->movement &= ~(BKWD);
}

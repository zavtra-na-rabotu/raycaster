/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:03 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:06 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	event_handler(t_game *game, SDL_Event *e)
{
	if (e->type == SDL_QUIT)
		game->running = 0;
	if (e->type == SDL_KEYDOWN)
		key_down_handler(game, e);
	if (e->type == SDL_KEYUP)
	{
		if (e->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		{
			game->running = 0;
			return ;
		}
		key_up_handler(game, e);
	}
	if (e->type == SDL_MOUSEMOTION)
		mouse_move_handler(game, e);
}

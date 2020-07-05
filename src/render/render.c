/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <pkunze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:24 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/22 13:38:07 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "update.h"
#include "sprite.h"

void	render_all(t_game *game)
{
	render_world(game, game->player);
	render_sprites(game, game->player);
	SDL_UpdateTexture(game->world_texture, NULL, game->buf, W_W * 4);
	SDL_RenderCopy(game->renderer, game->world_texture, NULL, NULL);
	render_stats(game);
	SDL_RenderPresent(game->renderer);
	update_world(game);
}

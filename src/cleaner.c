/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clean.h"

int	clean_and_quit(t_game *game, int code)
{
	clean_textures(game->txtrs);
	clean_fonts(game->fonts);
	clean_doors(game->doors);
	clean_sprites(game->sprites);
	clean_buffer(game->buf);
	clean_z_buffer(game->z_buf);
	if (game->world_texture)
		SDL_DestroyTexture(game->world_texture);
	if (game->map)
		clean_map(game->map, game->map_dim.x);
	if (game->renderer)
		SDL_DestroyRenderer(game->renderer);
	if (game->window)
		SDL_DestroyWindow(game->window);
	TTF_Quit();
	SDL_Quit();
	return (code);
}

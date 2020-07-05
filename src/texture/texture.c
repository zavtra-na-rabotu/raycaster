/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:01 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:04 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "texture.h"

void			create_world_texture(t_game *game)
{
	game->world_texture =
		SDL_CreateTexture(game->renderer, SDL_PIXELFORMAT_RGBA32,
				SDL_TEXTUREACCESS_STREAMING, W_W, W_H);
}

static int		malloc_for_textures(t_game *g)
{
	int spr;

	spr = sizeof(void *);
	g->txtrs = malloc(sizeof(SDL_Surface**) * ENTITIES);
	if (!g->txtrs)
		return (ERR);
	g->txtrs[WALLS] = ft_memalloc(sizeof(SDL_Surface*) * WAL_TXRS + spr);
	if (!g->txtrs[WALLS])
		return (ERR);
	g->txtrs[DOORS] = ft_memalloc(sizeof(SDL_Surface *) * DOR_TXRS + spr);
	if (!g->txtrs[DOORS])
		return (ERR);
	g->txtrs[FLORS] = ft_memalloc(sizeof(SDL_Surface *) * FLR_TXRS + spr);
	if (!g->txtrs[FLORS])
		return (ERR);
	g->txtrs[CEILS] = ft_memalloc(sizeof(SDL_Surface *) * CEL_TXRS + spr);
	if (!g->txtrs[CEILS])
		return (ERR);
	g->txtrs[SPRTS] = ft_memalloc(sizeof(SDL_Surface *) * SRT_TXRS + spr);
	if (!g->txtrs[SPRTS])
		return (ERR);
	return (OK);
}

SDL_Surface		*load_surface(t_game *game, char *path)
{
	SDL_Surface *surface;

	surface = IMG_Load(path);
	if (!surface)
	{
		sdl_error("Unable to load image", IMG_GetError());
		clean_and_quit(game, ERR);
		exit(ERR);
	}
	return (surface);
}

int				load_textures(t_game *g)
{
	if (malloc_for_textures(g) != OK)
		return (ERR);
	load_wall_textures(g);
	load_door_textures(g);
	load_floor_textures(g);
	load_ceiling_textures(g);
	load_sprite_textures(g);
	return (OK);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:40 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	init_sdl(void)
{
	SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		return (sdl_error("Could not init SDL:", SDL_GetError()));
	SDL_SetRelativeMouseMode(SDL_TRUE);
	return (OK);
}

int	init_ttf(void)
{
	if (TTF_Init() == -1)
		return (sdl_error("Could not init TTF:", TTF_GetError()));
	return (OK);
}

int	create_window(t_game *game)
{
	game->window = SDL_CreateWindow("Wold 3D", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_OPENGL);
	if (game->window == NULL)
		return (sdl_error("Could not create window:", SDL_GetError()));
	return (OK);
}

int	create_renderer(t_game *game)
{
	game->renderer = SDL_CreateRenderer(game->window, -1,
													SDL_RENDERER_ACCELERATED);
	if (game->renderer == NULL)
		return (sdl_error("Could not create renderer:", SDL_GetError()));
	return (OK);
}

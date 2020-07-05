/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <pkunze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/22 13:48:11 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "door.h"
#include "font.h"
#include "texture.h"

void	init_game(t_game *g)
{
	g->buf = NULL;
	g->z_buf = NULL;
	g->txtrs = NULL;
	g->doors = NULL;
	g->sprites = NULL;
	g->world_texture = NULL;
	g->map = NULL;
	g->renderer = NULL;
	g->window = NULL;
}

int		prepare_everything_for_game(t_game *g)
{
	t_player player;

	if (init_sdl() != OK)
		return (clean_and_quit(g, ERR));
	if (init_ttf() != OK)
		return (clean_and_quit(g, ERR));
	if (create_window(g) != OK)
		return (clean_and_quit(g, ERR));
	if (create_renderer(g) != OK)
		return (clean_and_quit(g, ERR));
	create_world_texture(g);
	init_player(g, &player);
	load_fonts(g);
	if (find_doors(g->map, &g->doors, &g->doors_num, g->map_dim) != OK)
		return (clean_and_quit(g, ERR));
	if (load_textures(g) != OK)
		return (clean_and_quit(g, ERR));
	if (!(g->buf = malloc(sizeof(SDL_Color) * W_W * W_H)))
		return (clean_and_quit(g, ERR));
	if (!(g->z_buf = malloc(sizeof(double) * W_W)))
		return (clean_and_quit(g, ERR));
	play_background(g);
	g->running = 1;
	start_game_loop(g);
	return (clean_and_quit(g, OK));
}

void	start_game_loop(t_game *game)
{
	SDL_Event	event;
	uint32_t	frame_delay;
	uint32_t	frame_start;
	uint32_t	frame_time;

	frame_delay = 1000 / FPS_MAX;
	game->fps = 0;
	while (game->running)
	{
		frame_start = SDL_GetTicks();
		update_player(game);
		render_all(game);
		while (SDL_PollEvent(&event))
			event_handler(game, &event);
		frame_time = SDL_GetTicks() - frame_start;
		if (frame_delay > frame_time)
		{
			SDL_Delay(frame_delay - frame_time);
			game->fps = 1000 / (frame_time + (frame_delay - frame_time));
		}
		else
			game->fps = 1000 / frame_time;
	}
}

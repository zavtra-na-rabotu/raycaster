/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_GAME_H
# define WOLF3D_GAME_H

# include "player.h"
# include "point.h"
# include "door.h"
# include "map.h"

# include <math.h>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_events.h>
# include <SDL2/SDL_ttf.h>

# define W_H 800
# define W_W 1200

# define FONTS 1

typedef struct		s_game
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		***txtrs;
	TTF_Font		*fonts[FONTS];
	t_player		*player;
	SDL_Color		*buf;
	double			*z_buf;
	int				running;
	t_i_pt			map_dim;
	t_map_tile		**map;
	int				sprt_num;
	t_sprite		*sprites;
	t_door			*doors;
	int				doors_num;
	unsigned int	fps;
	SDL_Texture		*world_texture;
}					t_game;

void				move_player(t_player *p, t_game *g);
void				check_player_position(t_game *game);
void				init_game(t_game *g);

#endif

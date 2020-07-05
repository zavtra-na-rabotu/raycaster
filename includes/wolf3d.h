/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:36 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_WOLF3D_H
# define WOLF3D_WOLF3D_H

# include "libft.h"
# include "event.h"
# include "game.h"
# include "validator.h"

# define TILE_SIZE 1

# define FPS_MAX 90

# define TEXTURE_H 512
# define TEXTURE_W 512

# define OK 0
# define ERR 1

# define G_VALUE 10
# define SCORE_MAX 999

typedef enum	e_hit_side {
	X,
	Y
}				t_hit_side;

typedef struct	s_line
{
	int			start;
	int			end;
	int			height;
}				t_line;

typedef struct	s_ray
{
	t_d_pt		dir;
	t_d_pt		delta_dist;
	t_d_pt		side_dist;
	t_d_pt		half_step;
	t_i_pt		step;
	int			hit;
	t_hit_side	hit_side;
}				t_ray;

typedef struct	s_rndr_stat
{
	double		wall_dist;
	double		tile_x;
	double		cam_x;
	t_door		door;
	t_line		column;
	t_line		y;
	int			tex_x;
	int			x;
}				t_r_st;

typedef struct	s_floor_pack
{
	t_game		*g;
	t_ray		*ray;
	t_r_st		*state;
	t_line		*line;
	int			x;

}				t_floor_pack;

int				error(char *e);
int				sdl_error(char *message, const char *error);

void			create_world_texture(t_game *game);
int				init_sdl();
int				init_ttf();
int				create_window(t_game *game);
int				create_renderer(t_game *game);
int				clean_and_quit(t_game *game, int code);

int				prepare_everything_for_game(t_game *g);
void			start_game_loop(t_game *game);

void			render_all(t_game *game);

void			init_player(t_game *game, t_player *player);
void			update_player(t_game *game);

void			render_world(t_game *g, t_player *p);
void			render_stats(t_game *g);

void			play_background(t_game *g);

void			interaction(t_game *g);

t_map_tile		get_tile(t_game *g, int x, int y);

int				door_hit(t_game *g, t_player *p, t_r_st *s, double w_h);

void			cast_ray(t_game *g, t_ray *ray, t_player *p, t_r_st *s);

void			draw_floor_ceil(t_floor_pack pack);

void			draw_walls(SDL_Color *buff, SDL_Surface	*surface, t_r_st *st);
double			calc_wall_dist(t_player *p, t_ray *r);
SDL_Surface		*choose_wall_texture(t_game *g, t_player *p, t_ray *ray);

SDL_Color		get_color(SDL_Surface *surface, int x, int y);

#endif

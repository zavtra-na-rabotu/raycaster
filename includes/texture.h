/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_TEXTURE_H
# define WOLF3D_TEXTURE_H

# define WALLS 0
# define DOORS 1
# define FLORS 2
# define CEILS 3
# define SPRTS 4

# define ENTITIES 5

# define WAL_TXRS 10
# define DOR_TXRS 1
# define FLR_TXRS 4
# define CEL_TXRS 3
# define SRT_TXRS 7

SDL_Surface		*load_surface(t_game *game, char *path);
int				load_textures(t_game *game);
void			load_wall_textures(t_game *g);
void			load_door_textures(t_game *g);
void			load_floor_textures(t_game *g);
void			load_ceiling_textures(t_game *g);
void			load_sprite_textures(t_game *g);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_CLEAN_H
# define WOLF3D_CLEAN_H

# include "game.h"
# include "door.h"

void clean_textures(SDL_Surface ***textures);
void clean_fonts(TTF_Font **fonts);
void clean_doors(t_door *doors);
void clean_map(t_map_tile **map, int width);
void clean_sprites(t_sprite *sprites);
void clean_z_buffer(double *buff);
void clean_buffer(SDL_Color *buff);
void *clean_map_and_close_fd(int fd, t_map_tile **map, int width);
void *clean_sprites_and_close_fd(int fd, t_sprite *sprites);

#endif

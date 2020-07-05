/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:24 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:26 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Color	get_color(SDL_Surface *surface, int x, int y)
{
	uint8_t *color;

	color = surface->pixels
			+ surface->pitch * y
			+ surface->format->BytesPerPixel * x;
	return ((SDL_Color){color[0], color[1], color[2], color[3]});
}

t_map_tile	get_tile(t_game *g, int x, int y)
{
	return (g->map[x][y]);
}

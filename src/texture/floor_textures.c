/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:01 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:04 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	load_floor_textures(t_game *g)
{
	g->txtrs[FLORS][0] = load_surface(g, "res/textures/floor/warcraft.jpg");
	g->txtrs[FLORS][1] = load_surface(g, "res/textures/floor/cobble.jpg");
	g->txtrs[FLORS][2] = load_surface(g, "res/textures/floor/stone.jpg");
	g->txtrs[FLORS][3] = load_surface(g, "res/textures/floor/grass.png");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:01 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:03 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	load_wall_textures(t_game *g)
{
	g->txtrs[WALLS][0] = load_surface(g, "res/textures/wall/brick.jpg");
	g->txtrs[WALLS][1] = load_surface(g, "res/textures/wall/cobble.jpg");
	g->txtrs[WALLS][2] = load_surface(g, "res/textures/wall/brick2.png");
	g->txtrs[WALLS][3] = load_surface(g, "res/textures/wall/tron.jpg");
	g->txtrs[WALLS][4] = load_surface(g, "res/textures/wall/water.png");
	g->txtrs[WALLS][5] = load_surface(g, "res/textures/wall/wood1.jpg");
	g->txtrs[WALLS][6] = load_surface(g, "res/textures/wall/wood2.jpg");
	g->txtrs[WALLS][7] = load_surface(g, "res/textures/wall/wood3.jpg");
	g->txtrs[WALLS][8] = load_surface(g, "res/textures/wall/wood4.jpg");
	g->txtrs[WALLS][9] = load_surface(g, "res/textures/wall/wood5.jpg");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:01 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:04 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	load_sprite_textures(t_game *g)
{
	g->txtrs[SPRTS][0] = load_surface(g, "res/textures/sprites/barrel.png");
	g->txtrs[SPRTS][1] = load_surface(g, "res/textures/sprites/tree.png");
	g->txtrs[SPRTS][2] = load_surface(g, "res/textures/sprites/grass.png");
	g->txtrs[SPRTS][3] = load_surface(g, "res/textures/sprites/msh1.png");
	g->txtrs[SPRTS][4] = load_surface(g, "res/textures/sprites/msh2.png");
	g->txtrs[SPRTS][5] = load_surface(g, "res/textures/sprites/msh3.png");
	g->txtrs[SPRTS][6] = load_surface(g, "res/textures/sprites/msh4.png");
}

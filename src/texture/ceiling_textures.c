/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:01 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:04 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	load_ceiling_textures(t_game *g)
{
	g->txtrs[CEILS][0] = load_surface(g, "res/textures/ceil/ceil.png");
	g->txtrs[CEILS][1] = load_surface(g, "res/textures/ceil/stone.jpg");
	g->txtrs[CEILS][2] = load_surface(g, "res/textures/ceil/wood.jpg");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:01 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:04 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"

void	load_door_textures(t_game *g)
{
	g->txtrs[DOORS][0] = load_surface(g, "res/textures/door/security.jpg");
}

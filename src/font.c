/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static TTF_Font	*load_font(t_game *game, char *path, int size)
{
	TTF_Font *font;

	font = TTF_OpenFont(path, size);
	if (!font)
	{
		sdl_error("Unable to load font", TTF_GetError());
		clean_and_quit(game, ERR);
		exit(ERR);
	}
	return (font);
}

void			load_fonts(t_game *g)
{
	g->fonts[0] = load_font(g, "res/fonts/Hack-Regular.ttf", 48);
}

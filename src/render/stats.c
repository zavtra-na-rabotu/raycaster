/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:24 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:25 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_text(t_game *g, char *text)
{
	SDL_Surface	*srfc;
	SDL_Texture	*message;
	SDL_Rect	message_rect;

	srfc = TTF_RenderText_Solid(g->fonts[0], text, (SDL_Color){10, 255, 10, 0});
	message = SDL_CreateTextureFromSurface(g->renderer, srfc);
	message_rect.x = 10;
	message_rect.y = 10;
	message_rect.w = 250;
	message_rect.h = 30;
	SDL_FreeSurface(srfc);
	SDL_RenderCopy(g->renderer, message, NULL, &message_rect);
	SDL_DestroyTexture(message);
}

void	render_stats(t_game *g)
{
	char *score;
	char *fps;
	char text[20];

	fps = ft_itoa(g->fps);
	score = ft_itoa((int)g->player->score);
	text[0] = 0;
	ft_strcat(text, "FPS: ");
	ft_strcat(text, fps);
	ft_strcat(text, " SCORE: ");
	ft_strcat(text, score);
	render_text(g, text);
	free(score);
	free(fps);
}

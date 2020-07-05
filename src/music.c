/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	play_background(t_game *g)
{
	Mix_Music	*music;
	int			channel;

	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096) != 0)
	{
		sdl_error("Unable to initialize audio: ", Mix_GetError());
		clean_and_quit(g, ERR);
	}
	music = Mix_LoadMUS("res/sounds/music/gribi.ogg");
	if (!music)
		sdl_error("Unable to load music file: ", Mix_GetError());
	channel = Mix_PlayMusic(music, 999);
	if (channel == -1)
		sdl_error("Unable to play music file: ", Mix_GetError());
}

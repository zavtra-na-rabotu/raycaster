/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:48:40 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:48:47 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "texture.h"

void	clean_textures(SDL_Surface ***textures)
{
	int i;
	int k;

	i = 0;
	while (i < ENTITIES)
	{
		if (textures[i])
		{
			k = 0;
			while (textures[i][k])
			{
				SDL_FreeSurface(textures[i][k]);
				k++;
			}
			free(textures[i]);
		}
		i++;
	}
	free(textures);
}

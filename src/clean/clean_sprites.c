/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:48:40 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:48:47 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clean_sprites(t_sprite *sprites)
{
	if (sprites)
		free(sprites);
}

void	*clean_sprites_and_close_fd(int fd, t_sprite *sprites)
{
	close(fd);
	if (sprites)
		free(sprites);
	return (NULL);
}

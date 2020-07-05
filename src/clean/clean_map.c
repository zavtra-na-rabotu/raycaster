/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:48:40 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:48:47 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clean_map(t_map_tile **map, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	*clean_map_and_close_fd(int fd, t_map_tile **map, int width)
{
	close(fd);
	clean_map(map, width);
	return (NULL);
}

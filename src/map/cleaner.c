/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:14 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:17 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "clean.h"

void	*clean_line_and_close_fd(int fd, char *line)
{
	if (line)
		free(line);
	close(fd);
	return (NULL);
}

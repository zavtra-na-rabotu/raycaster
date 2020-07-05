/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	error(char *e)
{
	ft_putendl(e);
	ft_putendl("Usage: wolf3d [map]");
	return (ERR);
}

int	sdl_error(char *message, const char *error)
{
	ft_putendl(message);
	ft_putendl(error);
	return (ERR);
}

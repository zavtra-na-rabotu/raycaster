/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_COLLISION_H
# define WOLF3D_COLLISION_H

# include "game.h"

int		collision(t_game *g, int x, int y);
void	collect_sprite(t_game *g);
int		can_move(t_game *g, double x, double y);

#endif

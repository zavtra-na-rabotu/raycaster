/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:51:11 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:15 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	update_player(t_game *game)
{
	rotate_player(game->player);
	move_player(game->player, game);
	check_player_position(game);
}

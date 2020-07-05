/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_EVENT_H
# define WOLF3D_EVENT_H

# include "game.h"

# define MOUSE_SENS 0.002

void	event_handler(t_game *game, SDL_Event *event);
void	key_down_handler(t_game *game, SDL_Event *e);
void	key_up_handler(t_game *game, SDL_Event *e);
void	mouse_move_handler(t_game *game, SDL_Event *e);

#endif

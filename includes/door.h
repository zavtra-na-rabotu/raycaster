/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DOOR_H
# define WOLF3D_DOOR_H

# define DOOR_SLIDE 0.02

# define OPENED 1u << 0u
# define CLOSED 1u << 1u
# define OPENING 1u << 2u
# define CLOSING 1u << 3u

# include "map.h"

typedef struct		s_door
{
	int				x;
	int				y;
	unsigned int	state;
	double			moving;
}					t_door;

void				open_close_door(t_door *doors, int doors_num, int x, int y);
t_door				*find_door(t_door *doors, int doors_num, int x, int y);
int					find_doors(t_map_tile **m, t_door **d, int *n, t_i_pt md);

#endif

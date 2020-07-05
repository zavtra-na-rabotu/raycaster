/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_SPRITE_H
# define WOLF3D_SPRITE_H

# include "wolf3d.h"

typedef struct	s_sprite_pack
{
	SDL_Surface	*surface;
	t_line		x;
	t_line		y;
	t_d_pt		t;
	t_i_pt		from;
	t_sprite	*sprt;
	int			sprt_w;
	int			sprt_h;
	int			sprt_scr_x;
	int			v_off;
	double		inv_det;
}				t_sprite_pack;

void			render_sprites(t_game *g, t_player *p);
double			distance_to_sprite(t_player *p, t_sprite *s);
void			sort_sprites(t_game *g, t_player *p, int *sprt_order);

#endif

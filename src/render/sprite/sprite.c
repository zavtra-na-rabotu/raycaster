/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:35 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:36 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "texture.h"
#include "sprite.h"

static void	calc_sprite_width(t_sprite_pack *sp)
{
	sp->sprt_scr_x = (int)((W_W / 2.) * (1 + sp->t.x / sp->t.y));
	sp->sprt_w = (W_H / (sp->t.y)) / sp->sprt->scale.x;
	sp->x.start = sp->sprt_scr_x - sp->sprt_w / 2;
	sp->from.x = sp->x.start;
	if (sp->x.start < 0)
		sp->x.start = 0;
	sp->x.end = sp->sprt_scr_x + sp->sprt_w / 2;
	if (sp->x.end >= W_W)
		sp->x.end = W_W;
}

static void	calc_sprite_height(t_sprite_pack *sp)
{
	sp->sprt_h = (W_H / sp->t.y) / sp->sprt->scale.y;
	sp->y.start = (W_H - sp->sprt_h) / 2 + sp->v_off;
	sp->from.y = sp->y.start;
	if (sp->y.start < 0)
		sp->y.start = 0;
	sp->y.end = (W_H + sp->sprt_h) / 2 + sp->v_off;
	if (sp->y.end >= W_H)
		sp->y.end = W_H;
}

static void	translate_sprite_pos(t_sprite_pack *sp, t_player *p)
{
	t_d_pt sprt;

	sprt.x = sp->sprt->coords.x - p->x;
	sprt.y = sp->sprt->coords.y - p->y;
	sp->inv_det = 1. / (p->plane.x * p->dir.y - p->dir.x * p->plane.y);
	sp->t.x = sp->inv_det * (p->dir.y * sprt.x - p->dir.x * sprt.y);
	sp->t.y = sp->inv_det * (-p->plane.y * sprt.x + p->plane.x * sprt.y);
	sp->v_off = (int)(sp->sprt->v_off / sp->t.y);
}

static void	draw_sprite(t_game *g, t_sprite_pack *sp)
{
	t_i_pt		tex;
	int			x;
	int			y;
	SDL_Color	c;

	sp->surface = g->txtrs[SPRTS][sp->sprt->txtr - 1];
	x = sp->x.start;
	while (x < sp->x.end)
	{
		if (x > 0 && x < W_W && sp->t.y > 0 && sp->t.y < g->z_buf[x])
		{
			tex.x = (x - sp->from.x) * sp->surface->w / sp->sprt_w;
			y = sp->y.start;
			while (y < sp->y.end)
			{
				tex.y = (y - sp->from.y) * sp->surface->h / sp->sprt_h;
				c = get_color(sp->surface, tex.x, tex.y);
				g->buf[W_W * y + x] = c.a ? c : g->buf[W_W * y + x];
				y++;
			}
		}
		x++;
	}
}

void		render_sprites(t_game *g, t_player *p)
{
	t_sprite_pack	sp;
	int				sprt_order[g->sprt_num];
	int				i;

	sort_sprites(g, p, sprt_order);
	i = 0;
	while (i < g->sprt_num)
	{
		if (g->sprites[sprt_order[i]].collected)
		{
			i++;
			continue;
		}
		sp.sprt = &g->sprites[sprt_order[i]];
		translate_sprite_pos(&sp, p);
		if (sp.t.y <= 0.)
		{
			i++;
			continue;
		}
		calc_sprite_height(&sp);
		calc_sprite_width(&sp);
		draw_sprite(g, &sp);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:43 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:47 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "texture.h"

t_d_pt	get_flr_tex_point(t_ray *ray, t_player *p, t_r_st *state)
{
	t_d_pt	flr_tex;

	if (ray->hit_side == X && ray->dir.x > 0)
		flr_tex = (t_d_pt){p->map.x, p->map.y + state->tile_x};
	else if (ray->hit_side == X && ray->dir.x < 0)
		flr_tex = (t_d_pt){p->map.x + 1., p->map.y + state->tile_x};
	else if (ray->hit_side == Y && ray->dir.y > 0)
		flr_tex = (t_d_pt){p->map.x + state->tile_x, p->map.y};
	else
		flr_tex = (t_d_pt){p->map.x + state->tile_x, p->map.y + 1.};
	return (flr_tex);
}

void	get_tex_texnum(t_d_pt *tex, t_i_pt *tex_num, t_floor_pack p, int y)
{
	t_d_pt	flr_tex;
	t_d_pt	flr;
	t_d_pt	dis_w;

	flr_tex = get_flr_tex_point(p.ray, p.g->player, p.state);
	dis_w.x = W_H / (2. * y - W_H);
	dis_w.y = dis_w.x / p.state->wall_dist;
	flr.x = (dis_w.y * (flr_tex.x + p.ray->half_step.x)
											+ (1. - dis_w.y) * p.g->player->x);
	flr.y = (dis_w.y * (flr_tex.y + p.ray->half_step.y)
											+ (1. - dis_w.y) * p.g->player->y);
	tex_num->x = p.g->map[(int)flr.x][(int)flr.y].floor - 1;
	tex_num->y = p.g->map[(int)flr.x][(int)flr.y].ceil - 1;
	tex->x = (int)(flr.x * TEXTURE_W) % TEXTURE_W;
	tex->y = (int)(flr.y * TEXTURE_H) % TEXTURE_H;
}

void	draw_floor_ceil(t_floor_pack p)
{
	t_d_pt	tex;
	t_i_pt	tex_num;
	int		y;

	p.line->end = p.line->end < 0 ? W_H : p.line->end;
	y = p.line->end + 1;
	while (y < W_H)
	{
		get_tex_texnum(&tex, &tex_num, p, y);
		p.g->buf[(W_W * y) + p.x] = get_color(p.g->txtrs[FLORS][tex_num.x],
																tex.x, tex.y);
		p.g->buf[(W_H - y - 1) * W_W + p.x] =
						get_color(p.g->txtrs[CEILS][tex_num.y], tex.x, tex.y);
		y++;
	}
}

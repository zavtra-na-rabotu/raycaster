/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:43 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:45 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "door.h"

static void	update_line_state(t_r_st *st, t_ray ray, t_player *p)
{
	st->wall_dist = calc_wall_dist(p, &ray);
	st->column.height = (int)(W_H / st->wall_dist);
	st->column.start = (W_H - st->column.height) / 2;
	st->y.start = st->column.start < 0 ? 0 : st->column.start;
	st->y.end = (W_H + st->column.height) / 2;
	st->y.end = st->y.end >= W_H ? W_H : st->y.end;
	st->tile_x = ray.hit_side == X ? p->y + st->wall_dist * ray.dir.y
										: p->x + st->wall_dist * ray.dir.x;
	st->tile_x -= floor(st->tile_x);
}

static void	calc_step(t_ray *ray, t_player *p)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (p->x - p->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (p->map.x + 1 - p->x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (p->y - p->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (p->map.y + 1 - p->y) * ray->delta_dist.y;
	}
}

static void	half_shift(t_r_st state, t_game *g, int *y)
{
	t_d_pt		shift_half;

	shift_half.x = state.tile_x;
	if (g->map[g->player->map.x][g->player->map.y].type == TYPE_DOOR)
	{
		shift_half.y = (1. - state.door.moving) / 2.;
		shift_half.x = state.tile_x < 0.5 ? shift_half.x + shift_half.y
											: shift_half.x - shift_half.y;
	}
	*y = (int)(shift_half.x * (double)TEXTURE_W);
}

static void	hitside(t_ray ray, int *y)
{
	if (ray.hit_side == X && ray.dir.x > 0)
		*y = TEXTURE_W - *y - 1;
	if (ray.hit_side == Y && ray.dir.y < 0)
		*y = TEXTURE_W - *y - 1;
}

void		render_world(t_game *g, t_player *p)
{
	t_ray		ray;
	t_r_st		state;

	state.x = 0;
	while (state.x < W_W)
	{
		p->map = i_pt((int)p->x, (int)p->y);
		state.cam_x = 2 * state.x / (double)W_W - 1;
		ray.dir = d_pt(p->dir.x + p->plane.x * state.cam_x,
						p->dir.y + p->plane.y * state.cam_x);
		ray.delta_dist = d_pt(fabs(1 / ray.dir.x), fabs(1 / ray.dir.y));
		calc_step(&ray, p);
		cast_ray(g, &ray, p, &state);
		update_line_state(&state, ray, p);
		half_shift(state, g, &state.tex_x);
		hitside(ray, &state.tex_x);
		draw_walls(g->buf, choose_wall_texture(g, p, &ray), &state);
		draw_floor_ceil((t_floor_pack){g, &ray, &state, &state.y, state.x});
		g->z_buf[state.x] = state.wall_dist;
		state.x++;
	}
}

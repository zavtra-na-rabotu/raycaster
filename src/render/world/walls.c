/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:43 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:47 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "texture.h"

double		calc_wall_dist(t_player *p, t_ray *r)
{
	if (r->hit_side == X)
		return (((p->map.x + r->half_step.x) - p->x
											+ (1 - r->step.x) / 2.) / r->dir.x);
	else
		return (((p->map.y + r->half_step.y) - p->y
											+ (1 - r->step.y) / 2.) / r->dir.y);
}

SDL_Surface	*choose_wall_texture(t_game *g, t_player *p, t_ray *ray)
{
	int n;

	if (ray->hit_side == Y)
	{
		if (ray->step.y > 0)
			n = g->map[p->map.x][p->map.y].wall_w;
		else
			n = g->map[p->map.x][p->map.y].wall_e;
	}
	else
	{
		if (ray->step.x > 0)
			n = g->map[p->map.x][p->map.y].wall_n;
		else
			n = g->map[p->map.x][p->map.y].wall_s;
	}
	if (g->map[p->map.x][p->map.y].type == TYPE_DOOR)
		return (g->txtrs[DOORS][n - 1]);
	else
		return (g->txtrs[WALLS][n - 1]);
}

void		draw_walls(SDL_Color *buff, SDL_Surface *surface, t_r_st *st)
{
	int			y;
	int			column_y;
	int			tex_y;
	SDL_Color	color;

	y = st->y.start;
	while (y < st->y.end)
	{
		column_y = y - st->column.start;
		tex_y = TEXTURE_H * column_y / st->column.height;
		color = get_color(surface, st->tex_x, tex_y);
		buff[W_W * y + st->x] = color;
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:43 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:47 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "door.h"

void	door_handler(t_game *g, t_player *p, t_r_st *s, t_ray *r)
{
	t_d_pt half_dist;
	double wall_hit;

	if (r->hit_side == X)
	{
		half_dist.x = r->side_dist.x - r->delta_dist.x / 2;
		wall_hit = p->y + half_dist.x * r->dir.y;
		if ((half_dist.x < r->side_dist.y) && door_hit(g, p, s, wall_hit))
		{
			r->half_step.x = r->step.x / 2.;
			r->hit = 1;
		}
	}
	else
	{
		half_dist.y = r->side_dist.y - r->delta_dist.y / 2;
		wall_hit = p->x + half_dist.y * r->dir.x;
		if ((half_dist.y < r->side_dist.x) && door_hit(g, p, s, wall_hit))
		{
			r->half_step.y = r->step.y / 2.;
			r->hit = 1;
		}
	}
}

void	cast_ray(t_game *g, t_ray *ray, t_player *p, t_r_st *s)
{
	ray->half_step = (t_d_pt){0, 0};
	ray->hit_side = X;
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			p->map.x += ray->step.x;
			ray->hit_side = X;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			p->map.y += ray->step.y;
			ray->hit_side = Y;
		}
		if (get_tile(g, p->map.x, p->map.y).type == TYPE_DOOR)
			door_handler(g, p, s, ray);
		else if (get_tile(g, p->map.x, p->map.y).type == TYPE_WALL)
			ray->hit = 1;
	}
}

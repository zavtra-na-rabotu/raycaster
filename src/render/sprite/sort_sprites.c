/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:35 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:38 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "sprite.h"

static void	i_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	d_swap(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	quicksort(int *order, double *dist, int first, int last)
{
	t_i_pt	ij;
	int		pivot;

	if (first < last)
	{
		pivot = first;
		ij.x = first;
		ij.y = last;
		while (ij.x < ij.y)
		{
			while (dist[ij.x] >= dist[pivot] && ij.x < last)
				ij.x++;
			while (dist[ij.y] < dist[pivot])
				ij.y--;
			if (ij.x < ij.y)
			{
				d_swap(&dist[ij.x], &dist[ij.y]);
				i_swap(&order[ij.x], &order[ij.y]);
			}
		}
		d_swap(&dist[pivot], &dist[ij.y]);
		i_swap(&order[pivot], &order[ij.y]);
		quicksort(order, dist, first, ij.y - 1);
		quicksort(order, dist, ij.y + 1, last);
	}
}

void		sort_sprites(t_game *g, t_player *p, int *sprt_order)
{
	double	sprt_dist[g->sprt_num];
	int		i;

	i = 0;
	while (i < g->sprt_num)
	{
		sprt_order[i] = i;
		sprt_dist[i] = distance_to_sprite(p, &g->sprites[i]);
		i++;
	}
	quicksort(sprt_order, sprt_dist, 0, g->sprt_num - 1);
}

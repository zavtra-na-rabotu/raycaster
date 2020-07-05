/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_i_pt	i_pt(int x, int y)
{
	t_i_pt point;

	point.x = x;
	point.y = y;
	return (point);
}

t_d_pt	d_pt(double x, double y)
{
	t_d_pt point;

	point.x = x;
	point.y = y;
	return (point);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_POINT_H
# define WOLF3D_POINT_H

typedef struct	s_i_pt
{
	int			x;
	int			y;
}				t_i_pt;

typedef struct	s_d_pt
{
	double		x;
	double		y;
}				t_d_pt;

t_i_pt			i_pt(int x, int y);
t_d_pt			d_pt(double x, double y);

#endif

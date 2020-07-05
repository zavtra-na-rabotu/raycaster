/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:38:32 by pkunze            #+#    #+#             */
/*   Updated: 2019/09/14 17:38:38 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_MAP_H
# define WOLF3D_MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# include "point.h"

# define TYPE_WALL 100
# define TYPE_THIN_WALL 101
# define TYPE_SPRITE_DCRT 200
# define TYPE_SPRITE_CLSN 201
# define TYPE_SPRITE_PKBL 202
# define TYPE_SPRITE_ENMY 203
# define TYPE_DOOR 300
# define TYPE_EMPTY 500

typedef struct	s_sprite
{
	t_d_pt		coords;
	t_d_pt		scale;
	double		v_off;
	int			txtr;
	int			collected;
	int			type;
}				t_sprite;

typedef struct	s_map_tile
{
	int			ceil;
	int			floor;
	int			wall_n;
	int			wall_e;
	int			wall_s;
	int			wall_w;
	int			type;
}				t_map_tile;

t_map_tile		**parse_map(const char *map_file_path, t_i_pt *dims);
t_sprite		*parse_sprites(char *f, t_map_tile **m, int *s, t_i_pt d);
int				validate_parse_elem(int *e, char **line, char brkr, int m_v);

void			*clean_line_and_close_fd(int fd, char *line);

#endif

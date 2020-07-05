/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:14 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:49:17 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "clean.h"
#include "texture.h"

int			get_size_sprite(char *line, int *sprite)
{
	*sprite = ft_atoi(line);
	if (*sprite < 0)
		return (-1);
	return (1);
}

double		validate_parse_felem(double *e, char **ln, char brk, int ltz)
{
	*e = ft_atof(*ln);
	while (**ln && **ln != brk)
		*ln += 1;
	if (!(*ln) || (**ln) != brk)
	{
		if (!ltz && *e < 0)
			return (0);
	}
	*ln += 1;
	return (1);
}

t_sprite	parse_sprite(char *line, t_map_tile **map, t_i_pt dims)
{
	t_sprite	sprite;

	line++;
	if ((!validate_parse_felem(&sprite.coords.x, &line, ',', 0))
	|| (!validate_parse_felem(&sprite.coords.y, &line, ',', 0))
	|| (!validate_parse_felem(&sprite.scale.x, &line, ',', 0))
	|| (!validate_parse_felem(&sprite.scale.y, &line, ',', 0))
	|| (!validate_parse_felem(&sprite.v_off, &line, ',', 1))
	|| (!validate_parse_elem(&sprite.txtr, &line, '|', SRT_TXRS))
	|| (!validate_parse_elem(&sprite.type, &line, '}', INT_MAX))
	|| (!check_sprite_consistency(&sprite, dims)))
	{
		sprite.coords.x = -1;
		return (sprite);
	}
	sprite.collected = 0;
	if (map[(int)sprite.coords.x][(int)sprite.coords.y].type != TYPE_WALL)
		map[(int)sprite.coords.x][(int)sprite.coords.y].type = sprite.type;
	else
		sprite.coords.x = -1;
	return (sprite);
}

t_sprite	*deal_with_sprite_map(int fd, int *sprt_nm)
{
	char		*line;
	t_sprite	*sprites;

	line = NULL;
	if (get_next_line(fd, &line) <= 0)
		return (clean_line_and_close_fd(fd, NULL));
	else if (get_size_sprite(line, sprt_nm) < 0)
		return (clean_line_and_close_fd(fd, line));
	sprites = malloc(sizeof(*sprites) * (*sprt_nm));
	if (!sprites)
		return (clean_line_and_close_fd(fd, line));
	free(line);
	return (sprites);
}

t_sprite	*parse_sprites(char *fname, t_map_tile **m, int *sprt_nm, t_i_pt d)
{
	int			fd;
	char		*line;
	t_sprite	*sprites;
	int			i;

	fd = open(fname, O_RDONLY);
	if (fd < 3)
		return (NULL);
	line = NULL;
	if (!(sprites = deal_with_sprite_map(fd, sprt_nm)))
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		sprites[i] = parse_sprite(line, m, d);
		free(line);
		if (sprites[i].coords.x < 0)
			return (clean_sprites_and_close_fd(fd, sprites));
		i++;
		if (i > *sprt_nm)
			return (clean_sprites_and_close_fd(fd, sprites));
	}
	if (i < *sprt_nm)
		return (clean_sprites_and_close_fd(fd, sprites));
	return (sprites);
}

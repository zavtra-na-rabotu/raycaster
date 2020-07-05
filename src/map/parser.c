/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkunze <pkunze@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:49:14 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/22 13:32:37 by pkunze           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "clean.h"
#include "texture.h"

int			get_size_map(char *line, t_i_pt *wh)
{
	wh->x = ft_atoi(line);
	if (wh->x < 1)
		return (-1);
	wh->y = ft_atoi(line + ft_get_digits(wh->x, 10));
	if (wh->y < 1)
		return (-1);
	return (1);
}

int			validate_parse_elem(int *elem, char **line, char brkr, int max_val)
{
	*elem = ft_atoi(*line);
	(*line) += ft_get_digits(*elem, 10);
	if (!(*line) || (**line) != brkr || *elem < 0 || *elem > max_val)
		return (0);
	*line += 1;
	return (1);
}

t_map_tile	*validate_parse_line(char *line, int height)
{
	t_map_tile	*retline;
	int			i;

	i = 0;
	if (!(retline = malloc(sizeof(*retline) * height)))
		return (NULL);
	while (*line && i < height)
	{
		if ((!validate_parse_elem(&retline[i].ceil, &line, ',', CEL_TXRS))
		|| (!validate_parse_elem(&retline[i].floor, &line, ',', FLR_TXRS))
		|| (!validate_parse_elem(&retline[i].wall_n, &line, ',', WAL_TXRS))
		|| (!validate_parse_elem(&retline[i].wall_e, &line, ',', WAL_TXRS))
		|| (!validate_parse_elem(&retline[i].wall_s, &line, ',', WAL_TXRS))
		|| (!validate_parse_elem(&retline[i].wall_w, &line, '|', WAL_TXRS))
		|| (!validate_parse_elem(&retline[i].type, &line, ' ', INT_MAX))
		|| (!check_tile_consistency(retline[i])))
			break ;
		i++;
	}
	if (i != height - 1)
	{
		free(retline);
		return (NULL);
	}
	return (retline);
}

t_map_tile	**deal_with_map(int fd, t_i_pt *wh, t_i_pt *dims)
{
	char		*line;
	t_map_tile	**map;

	line = NULL;
	if (get_next_line(fd, &line) <= 0)
		return (clean_line_and_close_fd(fd, NULL));
	else if (get_size_map(line, wh) < 1)
		return (clean_line_and_close_fd(fd, line));
	map = malloc(wh->x * sizeof(*map) + (wh->x * (wh->y * sizeof(**map))));
	if (!map || wh->x < 3 || wh->y < 3)
		return (clean_line_and_close_fd(fd, line));
	dims->x = wh->x;
	dims->y = wh->y;
	wh->x = 0;
	free(line);
	return (map);
}

t_map_tile	**parse_map(const char *map_file_path, t_i_pt *dims)
{
	int			fd;
	t_i_pt		wh;
	char		*line;
	t_map_tile	**map;

	fd = open(map_file_path, O_RDONLY);
	if (fd < 3)
		return (NULL);
	line = NULL;
	if (!(map = deal_with_map(fd, &wh, dims)))
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		map[wh.x] = validate_parse_line(line, wh.y);
		free(line);
		if (!map[wh.x])
			return (clean_map_and_close_fd(fd, map, wh.x));
		wh.x++;
	}
	if (wh.x != dims->x)
		return (clean_map_and_close_fd(fd, map, wh.x));
	return (map);
}

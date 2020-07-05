/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edaella- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:45:34 by edaella-          #+#    #+#             */
/*   Updated: 2019/09/14 17:45:44 by edaella-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "clean.h"

int	map_border_check(t_map_tile **map, t_i_pt dims)
{
	int w;
	int h;

	w = 0;
	while (w < dims.x)
	{
		h = 0;
		while (h < dims.y)
		{
			if (w == 0 || h == 0 || w == dims.x - 1 || h == dims.y - 1)
			{
				if (map[w][h].type != TYPE_WALL &&
					map[w][h].type != TYPE_THIN_WALL)
					return (0);
			}
			h++;
		}
		w++;
	}
	return (1);
}

int	map_check(t_game *game, char **argv)
{
	char	*map_file;

	init_game(game);
	map_file = ft_strnew(ft_strlen(argv[1]) + 9);
	ft_strcat(map_file, "maps/");
	ft_strcat(map_file, argv[1]);
	ft_strcat(map_file, "/map");
	game->map = parse_map(map_file, &game->map_dim);
	free(map_file);
	if (game->map && game->map[1][1].type != TYPE_EMPTY)
	{
		clean_map(game->map, game->map_dim.x);
		game->map = NULL;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*itm_f;

	if (argc < 2)
		return (error("Error: not enough arguments"));
	map_check(&game, argv);
	if (!game.map)
		return (error("Error: invalid geometry map [Non-consistent]!"));
	if (!map_border_check(game.map, game.map_dim))
	{
		clean_map(game.map, game.map_dim.x);
		return (error("Error: invalid geometry map [Not border-bound]!"));
	}
	itm_f = ft_strnew(ft_strlen(argv[1]) + 9);
	ft_strcat(itm_f, "maps/");
	ft_strcat(itm_f, argv[1]);
	ft_strcat(itm_f, "/spr");
	game.sprites = parse_sprites(itm_f, game.map, &game.sprt_num, game.map_dim);
	free(itm_f);
	if (!game.sprites)
	{
		clean_map(game.map, game.map_dim.x);
		return (error("Error: invalid sprite map"));
	}
	return (prepare_everything_for_game(&game));
}

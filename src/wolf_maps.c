/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:18:45 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/17 02:06:53 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		init_tiles(t_wolf *wolf_game)
{
	int i;
	int j;

	j = -1;
	while (++j < 64)
	{
		i = -1;
		while (++i < 64)
		{
			wolf_game->tiles[j][i].type = TILE_FLOOR;
			wolf_game->tiles[j][i].block_player = 0;
		}
	}
}

/*
** Rules to get a valid map :
** Must have J player
** Length not more than LIMIT
*/

static int		verify_map(int fd)
{
	int		i;
	int		count;
	int		count_j;
	char	*line;

	i = 0;
	count = 0;
	count_j = 0;
	while ((i = get_next_line(fd, &line)) == 1)
	{
		if (ft_strlen(line) > 64)
			return (0);
		if (ft_strchr(line, 'J'))
			count_j++;
		ft_strdel(&line);
		count++;
	}
	ft_strdel(&line);
	if (count > 64 || count_j == 0)
		return (0);
	return (1);
}

static void		fill_tiles_at(int x, int y, char c, t_wolf *wolf_game)
{
	wolf_game->tiles[y][x].posx = x;
	wolf_game->tiles[y][x].posy = y;
	wolf_game->tiles[y][x].block_player = 0;
	if (c == 'J')
	{
		wolf_game->player_spawn_x = x * 10;
		wolf_game->player_spawn_y = y * 10;
	}
	else if (c == 'M')
	{
		wolf_game->tiles[y][x].type = TILE_WALL;
		wolf_game->tiles[y][x].block_player = 1;
	}
	else if (c == '*')
		wolf_game->tiles[y][x].type = TILE_SPACE;
	else if (c == 'S')
		wolf_game->tiles[y][x].type = TILE_SAS;
	else
		wolf_game->tiles[y][x].type = TILE_FLOOR;
}

static void		fill_tiles(int fd, t_wolf *wolf_game)
{
	int		i;
	int		j;
	int		count;
	char	*line;

	i = 0;
	count = 0;
	while ((i = get_next_line(fd, &line)) == 1)
	{
		j = -1;
		while (++j < ft_strlen(line))
			fill_tiles_at(j, count, line[j], wolf_game);
		ft_strdel(&line);
		count++;
	}
	ft_strdel(&line);
}

int				wolf_loadmap(char *mapfile, t_wolf *wolf_game)
{
	int fd;

	ft_putstr("Loading ");
	ft_putstr(mapfile);
	ft_putstr(" map...\n");
	if ((fd = open(mapfile, O_RDONLY)) > 0)
	{
		init_tiles(wolf_game);
		if (verify_map(fd) == 0)
			return (0);
		fill_tiles(open(mapfile, O_RDONLY), wolf_game);
	}
	else
		return (0);
	wolf_player_init(wolf_game);
	return (1);
}

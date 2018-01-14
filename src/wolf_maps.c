/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:18:45 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 16:47:44 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		init_tiles(char tiles[30][30])
{
	int i;
	int j;

	j = -1;
	while (++j < 30)
	{
		i = -1;
		while (++i < 30)
		{
			tiles[j][i] = '0';
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
		if (ft_strlen(line) > 30)
			return (0);
		if (ft_strchr(line, 'J'))
			count_j++;
		ft_strdel(&line);
		count++;
	}
	ft_strdel(&line);
	if (count > 30 || count_j == 0)
		return (0);
	return (1);
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
		{
			if (line[j] == 'J')
			{
				wolf_game->player.posx = j;
				wolf_game->player.posy = count;
			}
			else
				wolf_game->tiles[count][j] = line[j];
		}
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
		init_tiles(wolf_game->tiles);
		if (verify_map(fd) == 0)
			return (0);
		wolf_player_init(wolf_game);
		fill_tiles(open(mapfile, O_RDONLY), wolf_game);
	}
	else
		return (0);
	return (1);
}

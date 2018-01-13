/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:18:45 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/13 18:18:26 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		init_tiles(char tiles[1000][1000])
{
	int i;
	int j;

	j = -1;
	while (++j < 1000)
	{
		i = -1;
		while (++i < 1000)
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
		if (ft_strlen(line) > 1000)
			return (0);
		if (ft_strchr(line, 'J'))
			count_j++;
		count++;
	}
	if (count > 1000 || count_j == 0)
		return (0);
	return (1);
}

int				wolf_loadmap(char *mapfile, char tiles[1000][1000])
{
	int fd;

	ft_putstr("Loading ");
	ft_putstr(mapfile);
	ft_putstr(" map...\n");
	if ((fd = open(mapfile, O_RDONLY)) > 0)
	{
		init_tiles(tiles);
		if (verify_map(fd) == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/13 18:53:13 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		write_usage(void)
{
	ft_putendl("usage: ./fractol <map>");
	ft_putendl("\tRemplace <map> by a valid map file");
	exit(0);
}

int				main(int ac, char **av)
{
	t_wolf		wolf_game;
	int			i;
	int			j;

	if (ac != 2)
		write_usage();
	if (wolf_loadmap(av[1], wolf_game.tiles) == 1)
	{
		ft_putendl("valid map!");
		j = -1;
		while (++j < 50)
		{
			i = -1;
			while (++i < 50)
			{
				ft_putchar(wolf_game.tiles[j][i]);
			}
			ft_putchar('\n');
		}
		wolf_create_window(&wolf_game);
	}
	else
		ft_putendl("error: map not valid");
	return (0);
}

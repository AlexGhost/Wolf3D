/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:18:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/13 19:51:08 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		draw_cube(int x, int y, int color, t_wolf *wolf_game)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 18)
	{
		i = -1;
		while (++i < 18)
			wolf_game->smlx.imgstr[(x * 18 + j) + ((y * 18 + i) * WIN_WIDTH)] \
				= color;
	}
}

int				wolf_draw_minimap(t_wolf *wolf_game)
{
	int i;
	int j;

	j = -1;
	while (++j < 50)
	{
		i = -1;
		while (++i < 50)
		{
			if (wolf_game->tiles[j][i] == '0')
				draw_cube(i, j, 0x00FFFFFF, wolf_game);
		}
	}
	draw_cube(1, 1, 0x00FF0000, wolf_game);
	mlx_put_image_to_window(wolf_game->smlx.mlx, \
			wolf_game->smlx.win, wolf_game->smlx.img, 0, 0);
return (0);
}

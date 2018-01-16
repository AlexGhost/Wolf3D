/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:18:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/16 23:38:40 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		draw_player(double x, double y, t_wolf *wolf_game)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			wolf_game->smlx.imgstr[(int)(((int)x + j + 3 \
				+ 364) + (((int)y + i + 3 \
				+ 64) * WIN_WIDTH))] = COLOR_RED;
	}
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			wolf_game->smlx.imgstr[(int)(((int)x + j + 3 \
				+ (int)(wolf_game->player.rotx * 4) + 364) \
				+ (((int)y + i + 3 + (int)(wolf_game->player.roty * 4) \
				+ 64) * WIN_WIDTH))] = COLOR_RED - 0x00220000;
	}
}

static void		draw_cube(int x, int y, int color, t_wolf *wolf_game)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 10)
	{
		i = -1;
		while (++i < 10)
			wolf_game->smlx.imgstr[x * 10 + j + 364 \
				+ ((y * 10 + i + 64) * WIN_WIDTH)] = color;
	}
}

int				wolf_draw_minimap(t_wolf *wolf_game)
{
	int i;
	int j;

	wolf_player_loop(wolf_game);
	j = -1;
	while (++j < 64)
	{
		i = -1;
		while (++i < 64)
		{
			if (wolf_game->tiles[j][i].type == TILE_WALL)
				draw_cube(i, j, COLOR_DARKGREY, wolf_game);
			else if (wolf_game->tiles[j][i].type == TILE_SPACE)
				draw_cube(i, j, COLOR_LIGHTBLUE, wolf_game);
			else
				draw_cube(i, j, COLOR_LIGHTGREY, wolf_game);
		}
	}
	draw_player(wolf_game->player.posx, wolf_game->player.posy, wolf_game);
	mlx_put_image_to_window(wolf_game->smlx.mlx, \
			wolf_game->smlx.win, wolf_game->smlx.img, 0, 0);
	return (0);
}

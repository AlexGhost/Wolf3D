/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:18:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/15 15:11:55 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <stdio.h>

static void		draw_player(double x, double y, t_wolf *wolf_game)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			wolf_game->smlx.imgstr[(int)((x * 10 + j + 3 \
				+ (int)(WIN_WIDTH / 2.5)) + ((y * 10 + i + 3 \
				+ (int)(WIN_HEIGHT / 4)) * WIN_WIDTH))] = COLOR_RED;
	}
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4)
			wolf_game->smlx.imgstr[(int)((x * 10 + j + 3 \
				+ (int)(wolf_game->player.rotx * 10) + (int)(WIN_WIDTH / 2.5)) \
				+ ((y * 10 + i + 3 + (int)(wolf_game->player.roty * 10) \
				+ (int)(WIN_HEIGHT / 4)) * WIN_WIDTH))] = COLOR_GREEN;
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
			wolf_game->smlx.imgstr[(x * 10 + j + (int)(WIN_WIDTH / 2.5)) \
				+ ((y * 10 + i + (int)(WIN_HEIGHT / 4)) * WIN_WIDTH)] = color;
	}
}

int				wolf_draw_minimap(t_wolf *wolf_game)
{
	int i;
	int j;

	wolf_player_loop(wolf_game);
	j = -1;
	while (++j < 30)
	{
		i = -1;
		while (++i < 30)
		{
			if (wolf_game->tiles[j][i].type == TILE_WALL)
				draw_cube(i, j, 0x00555555, wolf_game);
			else
				draw_cube(i, j, 0x00BBBBBB, wolf_game);
		}
	}
	draw_player(wolf_game->player.posx, wolf_game->player.posy, wolf_game);
	mlx_put_image_to_window(wolf_game->smlx.mlx, \
			wolf_game->smlx.win, wolf_game->smlx.img, 0, 0);
	printf("Player Degree: %f,\trotx: %f, roty: %f\n", wolf_game->player.rot, wolf_game->player.rotx, wolf_game->player.roty);
	return (0);
}

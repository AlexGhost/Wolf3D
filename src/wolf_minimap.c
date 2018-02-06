/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:18:04 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/06 16:43:58 by acourtin         ###   ########.fr       */
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
				+ 364) + (((int)y + i + 3 + 64) * WIN_WIDTH))] = COLOR_RED;
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

static void		draw_tile(int i, int j, t_wolf *wolf_game)
{
	if (wolf_game->tiles[j][i].type == TILE_WALL)
		draw_cube(i, j, COLOR_WALL, wolf_game);
	else if (wolf_game->tiles[j][i].type == TILE_SPACE)
		draw_cube(i, j, COLOR_SPACE, wolf_game);
	else if (wolf_game->tiles[j][i].type == TILE_SAS)
		draw_cube(i, j, COLOR_SAS, wolf_game);
	else
		draw_cube(i, j, COLOR_FLOOR, wolf_game);
}

static void		begin_raycast(t_wolf *wolf_game)
{
	double	r;

	r = 0.0;
	while (r < 80)
	{
		if (wolf_game->draw_minimap == 1)
			wolf_throwray(r, wolf_game);
		else
			wolf_draw_wall(r, wolf_throwray(r, wolf_game), wolf_game);
		r += 0.35;
	}
}

int				wolf_draw_minimap(t_wolf *wolf_game)
{
	int		i;
	int		j;

	wolf_player_loop(wolf_game);
	wolf_draw_skybox(wolf_game);
	if (wolf_game->draw_minimap == 1 && (j = -1))
	{
		while (++j < 64)
		{
			i = -1;
			while (++i < 64)
				draw_tile(i, j, wolf_game);
		}
		draw_player(wolf_game->player.posx, wolf_game->player.posy, wolf_game);
	}
	begin_raycast(wolf_game);
	wolf_draw_hud(wolf_game);
	return (0);
}

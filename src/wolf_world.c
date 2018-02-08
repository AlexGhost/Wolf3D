/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/08 17:41:23 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			wolf_world_init(t_wolf *wolf_game)
{
	int i;
	int j;

	wolf_game->xpm_skybox.width = 0;
	wolf_game->xpm_skybox.height = 0;
	wolf_game->xpm_skybox.img = mlx_xpm_file_to_image(&wolf_game->smlx.mlx, \
		"xpm/skybox.xpm", &wolf_game->xpm_skybox.width, \
		&wolf_game->xpm_skybox.height);
	wolf_game->xpm_skybox.imgstr = (int*)mlx_get_data_addr(\
		wolf_game->xpm_skybox.img, &wolf_game->xpm_skybox.simg.bpp, \
		&wolf_game->xpm_skybox.simg.s_l, &wolf_game->xpm_skybox.simg.endian);
	j = -1;
	while (++j < 640)
	{
		i = -1;
		while (++i < 640)
		{
			wolf_game->hitbox[j][i].collision = \
				wolf_game->tiles[(j / 10)][(i / 10)].block_player;
			wolf_game->hitbox[j][i].oxygen = \
				wolf_game->tiles[(j / 10)][(i / 10)].have_atmo;
		}
	}
}

static int		inver(int n)
{
	int tab[101];
	int i;
	int j;

	i = 0;
	j = 100;
	while (i <= 100)
	{
		tab[i] = j;
		i++;
		j--;
	}
	return (tab[n]);
}

void			wolf_draw_wall(double col, int depth, t_wolf *wolf_game)
{
	int h;
	int color;

	depth = inver(depth);
	color = 0x00010102 * depth;
	h = -1;
	while (++h < (depth * 5) * cos((col - 40) / 180))
		wolf_game->smlx.imgstr[(int)(col * 17.5) + ((h + 400 \
			- (int)(depth * 3)) * WIN_WIDTH)] = color;
}

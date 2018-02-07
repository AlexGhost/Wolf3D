/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/07 16:34:42 by acourtin         ###   ########.fr       */
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
			wolf_game->collision[j][i] = \
				wolf_game->tiles[(j / 10)][(i / 10)].block_player;
	}
}

static int		inver(int n)
{
	int tab[31];
	int i;
	int j;

	i = 0;
	j = 30;
	while (i <= 30)
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
	int l;
	int color;

	depth = inver(depth);
	color = 0x00111111 * (depth / 5);
	h = -1;
	l = 0;
	while (++h < (depth * 5) * cos((col - 40) / 180))
	{
		l = -1;
		while (++l < 2)
			wolf_game->smlx.imgstr[(int)(col * 17.5) + l + ((h + 400 - depth) \
				* WIN_WIDTH)] = color;
	}
}

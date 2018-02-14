/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/13 19:16:22 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		load_xpm(t_wolf *wolf_game, t_xpm *xpm, char *xpm_name)
{
	xpm->width = 0;
	xpm->height = 0;
	xpm->img = mlx_xpm_file_to_image(&wolf_game->smlx.mlx, \
		xpm_name, &xpm->width, &xpm->height);
	xpm->imgstr = (int*)mlx_get_data_addr(\
		xpm->img, &xpm->simg.bpp, &xpm->simg.s_l, &xpm->simg.endian);
}

void			wolf_world_init(t_wolf *wolf_game)
{
	int i;
	int j;

	load_xpm(wolf_game, &wolf_game->xpm_skybox, "./xpm/skybox.xpm");
	load_xpm(wolf_game, &wolf_game->xpm_gun_idle, "./xpm/gun_idle.xpm");
	load_xpm(wolf_game, &wolf_game->xpm_gun_fire, "./xpm/gun_fire.xpm");
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
	while (++h < depth * 5)
		wolf_game->smlx.imgstr[(int)(col * 17.5) + ((h + 400 \
			- (int)(depth * 3)) * WIN_WIDTH)] = color;
}

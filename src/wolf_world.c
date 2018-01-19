/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:32:01 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/20 00:17:45 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void			clear_window(t_wolf *wolf_game)
{
	int i;

	i = -1;
	while (++i < WIN_HEIGHT * WIN_WIDTH)
		wolf_game->smlx.imgstr[i] = 0x00000000;
}

void				wolf_world_init(t_wolf *wolf_game)
{
	wolf_game->xpm_skybox.width = 0;
	wolf_game->xpm_skybox.height = 0;
	wolf_game->xpm_skybox.img = mlx_xpm_file_to_image(&wolf_game->smlx.mlx, \
		"xpm/skyboxmini.xpm", &wolf_game->xpm_skybox.width, \
		&wolf_game->xpm_skybox.height);
	wolf_game->xpm_skybox.imgstr = (int*)mlx_get_data_addr(\
		wolf_game->xpm_skybox.img, &wolf_game->xpm_skybox.simg.bpp, \
		&wolf_game->xpm_skybox.simg.s_l, &wolf_game->xpm_skybox.simg.endian);
}

static void			wolf_draw_skybox(t_wolf *wolf_game)
{
	int		i;
	int		j;
	char	*c;

	clear_window(wolf_game);
	j = -1;
	while (++j < 400)
	{
		i = -1;
		while (++i < 1400)
			wolf_game->smlx.imgstr[i + (j * WIN_WIDTH)] = \
				wolf_game->xpm_skybox.imgstr[i + (j * 1400)];
	}
	j = WIN_HEIGHT / 2 - 1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
			wolf_game->smlx.imgstr[i + (j * WIN_WIDTH)] = COLOR_FLOOR;
	}
}

void				wolf_draw_world(t_wolf *wolf_game)
{
	wolf_draw_skybox(wolf_game);
}

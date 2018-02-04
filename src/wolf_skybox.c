/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:09:50 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/04 14:18:48 by acourtin         ###   ########.fr       */
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
		"xpm/skybox.xpm", &wolf_game->xpm_skybox.width, \
		&wolf_game->xpm_skybox.height);
	wolf_game->xpm_skybox.imgstr = (int*)mlx_get_data_addr(\
		wolf_game->xpm_skybox.img, &wolf_game->xpm_skybox.simg.bpp, \
		&wolf_game->xpm_skybox.simg.s_l, &wolf_game->xpm_skybox.simg.endian);
}

void				wolf_draw_skybox(t_wolf *wolf_game)
{
	int		i;
	int		j;

	clear_window(wolf_game);
	i = -1;
	while (++i < (WIN_WIDTH * WIN_HEIGHT) / 2)
		wolf_game->smlx.imgstr[(int)(i \
			+ wolf_game->player.rot * 3.9)] = wolf_game->xpm_skybox.imgstr[i];
	i = (WIN_HEIGHT * WIN_WIDTH) / 2 - 1;
	while (++i < WIN_HEIGHT * WIN_WIDTH)
		wolf_game->smlx.imgstr[i] = COLOR_FLOOR;
}

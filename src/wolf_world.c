/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 18:32:01 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/19 05:15:11 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			wolf_world_init(t_wolf *wolf_game)
{
	wolf_game->xpm_skybox.width = 0;
	wolf_game->xpm_skybox.height = 0;
	wolf_game->xpm_skybox.img = mlx_xpm_file_to_image(&wolf_game->smlx.mlx, \
		"xpm/skybox.xpm", &wolf_game->xpm_skybox.width, \
		&wolf_game->xpm_skybox.height);
}

static void			wolf_draw_skybox(t_wolf *wolf_game)
{
	int i;
	int j;

	mlx_put_image_to_window(wolf_game->smlx.mlx, wolf_game->smlx.win, \
		wolf_game->xpm_skybox.img, 0, 0);
	/*j = WIN_HEIGHT / 2 - 1;
	while (++j < WIN_HEIGHT)
	{
		i = -1;
		while (++i < WIN_WIDTH)
			wolf_game->smlx.imgstr[i + (j * WIN_WIDTH)] = COLOR_FLOOR;
	}*/
}

void				wolf_draw_world(t_wolf *wolf_game)
{
	wolf_draw_skybox(wolf_game);
}

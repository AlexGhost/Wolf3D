/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:03:59 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/18 17:55:26 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void			draw_helmet(t_wolf *wolf_game)
{
	int i;
	int j;

	j = 727;
	while (++j < 780)
	{
		i = 30;
		while (++i < 240)
			wolf_game->smlx.imgstr[i + (j * WIN_WIDTH)] = COLOR_FLOOR;
	}
}

void				wolf_draw_hud(t_wolf *wolf_game)
{
	draw_helmet(wolf_game);
	mlx_put_image_to_window(wolf_game->smlx.mlx, \
			wolf_game->smlx.win, wolf_game->smlx.img, 0, 0);
	mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 50, 735, \
		COLOR_WALL, "STATUS");
	mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 50, 750, \
		COLOR_WALL, "O2 [   ]");
	mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 90, 750, \
		COLOR_WALL, ft_itoa(wolf_game->player.oxygen));
	if (wolf_game->player.oxygen > 50)
		mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 150, 750, \
			0x00247117, "ALIVE");
	else if (wolf_game->player.oxygen <= 50 && wolf_game->player.oxygen > 0)
	{
		if ((int)wolf_game->player.oxygen % 2)
			mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 130, 750, \
				0x00ED0000, "!!WARNING!!");
	}
	else
		mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 150, 750, \
			0x00A90000, "DECEASED");
}

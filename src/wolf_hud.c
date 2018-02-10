/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:03:59 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/10 19:27:12 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void			draw_gun(t_wolf *wolf_game)
{
	int i;

	i = -1;
	while (++i < (WIN_WIDTH * WIN_HEIGHT))
	{
		if (wolf_game->xpm_gun_idle.imgstr[i] != 0x00FFFFFF)
			wolf_game->smlx.imgstr[i] = wolf_game->xpm_gun_idle.imgstr[i];
	}
}

static void			draw_helmet(t_wolf *wolf_game)
{
	int i;
	int j;

	j = 727;
	while (++j < 780)
	{
		i = 30;
		while (++i < 240)
			wolf_game->smlx.imgstr[i + (j * WIN_WIDTH)] = COLOR_WALL;
	}
	if (!(wolf_game->draw_minimap == 1))
		draw_gun(wolf_game);
}

void				wolf_draw_hud(t_wolf *wolf_game)
{
	char *str_oxy;

	str_oxy = ft_itoa(wolf_game->player.oxygen);
	draw_helmet(wolf_game);
	mlx_put_image_to_window(wolf_game->smlx.mlx, \
			wolf_game->smlx.win, wolf_game->smlx.img, 0, 0);
	mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 50, 735, \
		COLOR_FLOOR, "STATUS");
	mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 50, 750, \
		COLOR_FLOOR, "O2 [   ]");
	mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 90, 750, \
		COLOR_FLOOR, str_oxy);
	if (wolf_game->player.oxygen > 50)
		mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 150, 750, \
			0x0057A44A, "ALIVE");
	else if (wolf_game->player.oxygen <= 50 && wolf_game->player.oxygen > 0)
	{
		if ((int)wolf_game->player.oxygen % 2)
			mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 130, 750, \
				0x00ED0000, "!!WARNING!!");
	}
	else
		mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 150, 750, \
			0x00A90000, "DECEASED");
	ft_strdel(&str_oxy);
}

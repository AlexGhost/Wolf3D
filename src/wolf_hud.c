/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:03:59 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/12 21:02:42 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void			draw_gun(t_wolf *wolf_game)
{
	int i;

	i = -1;
	while (++i < (WIN_WIDTH * WIN_HEIGHT))
	{
		if (wolf_game->player.is_firing == 0)
		{
			if (wolf_game->xpm_gun_idle.imgstr[i] != 0x0000FFFF)
				wolf_game->smlx.imgstr[i + (int)wolf_game->player.head_bob] = \
					wolf_game->xpm_gun_idle.imgstr[i];
		}
		else
		{
			if (wolf_game->xpm_gun_fire.imgstr[i] != 0x0000FFFF)
				wolf_game->smlx.imgstr[i + (int)wolf_game->player.head_bob] = \
					wolf_game->xpm_gun_fire.imgstr[i];
		}
	}
}

static void			draw_helmet(t_wolf *wolf_game)
{
	int i;
	int k;
	int j;

	j = 727;
	while (++j < 780)
	{
		i = 30;
		while (++i < 240)
			wolf_game->smlx.imgstr[i + (j * WIN_WIDTH)] = COLOR_WALL;
	}
	if (!(wolf_game->draw_minimap == 1) && wolf_game->draw_wep == 1 \
		&& wolf_game->player.oxygen > 0.0)
		draw_gun(wolf_game);
	wolf_firegun(wolf_game);
}

void				wolf_firegun(t_wolf *wolf_game)
{
	if (wolf_game->player.fire_timer <= 0.0)
	{
		wolf_game->player.fire_timer = GUN_FIRERATE;
		wolf_game->player.is_firing = 0;
	}
	else if (wolf_game->player.is_firing == 1)
	{
		wolf_game->player.fire_timer -= 0.1;
	}
}

static void			draw_ammocount(t_wolf *wolf_game)
{
	char *str_ammo;

	mlx_put_image_to_window(wolf_game->smlx.mlx, \
			wolf_game->smlx.win, wolf_game->smlx.img, 0, 0);
	str_ammo = ft_itoa(wolf_game->player.ammo);
	if (!(wolf_game->draw_minimap == 1) && wolf_game->draw_wep == 1 \
		&& wolf_game->player.oxygen > 0.0)
	{
		mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 890 + 10 \
			* wolf_game->player.is_firing + wolf_game->player.head_bob, \
			550 + 10 * wolf_game->player.is_firing, 0x00FFFFFF, "AMMO");
		mlx_string_put(wolf_game->smlx.mlx, wolf_game->smlx.win, 900 + 10 \
			* wolf_game->player.is_firing + wolf_game->player.head_bob, \
			565 + 10 * wolf_game->player.is_firing, 0x00FFFFFF, str_ammo);
	}
	ft_strdel(&str_ammo);
}

void				wolf_draw_hud(t_wolf *wolf_game)
{
	char *str_oxy;

	str_oxy = ft_itoa(wolf_game->player.oxygen);
	draw_helmet(wolf_game);
	draw_ammocount(wolf_game);
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

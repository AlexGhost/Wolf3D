/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:09:50 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/07 17:36:03 by acourtin         ###   ########.fr       */
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

void				wolf_draw_skybox(t_wolf *wolf_game)
{
	int		i;
	int		j;

	clear_window(wolf_game);
	if (!(wolf_game->draw_minimap == 1))
	{
		i = -1;
		while (++i < (WIN_WIDTH * WIN_HEIGHT) / 2)
			wolf_game->smlx.imgstr[(int)(i \
				+ wolf_game->player.rot * 3.9)] = wolf_game->xpm_skybox.imgstr[i];
		i = (WIN_HEIGHT * WIN_WIDTH) / 2 - 1;
		while (++i < WIN_HEIGHT * WIN_WIDTH)
			wolf_game->smlx.imgstr[i] = COLOR_FLOOR;
	}
}

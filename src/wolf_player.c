/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:23:12 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/15 17:56:51 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			wolf_player_init(t_wolf *wolf_game)
{
	wolf_game->player.posx = 1.0;
	wolf_game->player.posy = 1.0;
	wolf_game->player.rotx = 1.0;
	wolf_game->player.roty = 0.0;
	wolf_game->player.rot = 90.0;
	wolf_game->player.is_moving = 0;
	wolf_game->player.is_rot = 0;
}

void			wolf_player_loop(t_wolf *wolf_game)
{
	if (wolf_game->player.is_moving != 0)
	{
		wolf_game->player.posx += (wolf_game->player.is_moving * PLAYER_SPEED \
			* (wolf_game->player.rotx * 1));
		wolf_game->player.posy += (wolf_game->player.is_moving * PLAYER_SPEED \
			* (wolf_game->player.roty * 1));
	}
	if (wolf_game->player.is_rot != 0)
		wolf_game->player.rot += wolf_game->player.is_rot * PLAYER_TURN_RATE;
	if (wolf_game->player.posx < 0)
		wolf_game->player.posx = 0;
	else if (wolf_game->player.posx > 290)
		wolf_game->player.posx = 290;
	if (wolf_game->player.posy < 0)
		wolf_game->player.posy = 0;
	else if (wolf_game->player.posy > 290)
		wolf_game->player.posy = 290;
	if (wolf_game->player.rot > 360.0)
		wolf_game->player.rot = 0.0 + PLAYER_TURN_RATE;
	else if (wolf_game->player.rot < 0)
		wolf_game->player.rot = 360.0 - PLAYER_TURN_RATE;
	wolf_game->player.rotx = sin((wolf_game->player.rot / 180) * 3.14);
	wolf_game->player.roty = cos((wolf_game->player.rot / 180) * 3.14);
}

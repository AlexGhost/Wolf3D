/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:30:46 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 14:12:54 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int				wolf_keyevent(int keycode, t_wolf *wolf_game)
{
	if (keycode == BUTTON_ESCAPE)
		wolf_exit();
	wolf_game->player.posx += ((keycode == BUTTON_D) * PLAYER_SPEED);
	wolf_game->player.posx -= ((keycode == BUTTON_A) * PLAYER_SPEED);
	wolf_game->player.posy += ((keycode == BUTTON_S) * PLAYER_SPEED);
	wolf_game->player.posy -= ((keycode == BUTTON_W) * PLAYER_SPEED);
	if (wolf_game->player.posx < 0)
		wolf_game->player.posx = 0;
	if (wolf_game->player.posy < 0)
		wolf_game->player.posy = 0;
	if (wolf_game->player.posx > 29)
		wolf_game->player.posx = 29;
	if (wolf_game->player.posy > 29)
		wolf_game->player.posy = 29;
	return (0);
}

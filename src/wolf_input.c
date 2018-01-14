/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:30:46 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 13:46:24 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int				wolf_keyevent(int keycode, t_wolf *wolf_game)
{
	if (keycode == BUTTON_ESCAPE)
		wolf_exit();
	wolf_game->player.posx += (keycode == BUTTON_D);
	wolf_game->player.posx -= (keycode == BUTTON_A);
	wolf_game->player.posy += (keycode == BUTTON_S);
	wolf_game->player.posy -= (keycode == BUTTON_W);
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

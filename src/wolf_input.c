/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:30:46 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/17 02:47:19 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"
#include <stdio.h>

int				wolf_keyrelease_event(int keycode, t_wolf *wolf_game)
{
	if (keycode == BUTTON_ESCAPE)
		wolf_exit();
	else if (keycode == BUTTON_M)
		wolf_game->draw_minimap = -wolf_game->draw_minimap;
	else if (keycode == BUTTON_R)
		wolf_world_init(wolf_game);
	else if (keycode == BUTTON_D || keycode == BUTTON_A)
		wolf_game->player.is_rot = 0;
	else if (keycode == BUTTON_S || keycode == BUTTON_W)
		wolf_game->player.is_moving = 0;
	return (0);
}

int				wolf_keypress_event(int keycode, t_wolf *wolf_game)
{
	if (keycode == BUTTON_D || keycode == BUTTON_A)
		wolf_game->player.is_rot = (keycode == BUTTON_A) \
			+ (keycode == BUTTON_D) * -1;
	else if (keycode == BUTTON_S || keycode == BUTTON_W)
		wolf_game->player.is_moving = (keycode == BUTTON_W) \
			+ (keycode == BUTTON_S) * -1;
	return (0);
}

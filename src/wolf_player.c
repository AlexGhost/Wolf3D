/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 16:23:12 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/15 19:19:07 by acourtin         ###   ########.fr       */
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

static int		check_collisions(t_wolf *wolf_game)
{
	int		i;
	int		j;
	double	p_nx;
	double	p_ny;

	p_nx = wolf_game->player.posx \
		+ (int)(wolf_game->player.is_moving * wolf_game->player.rotx * 10);
	p_ny = wolf_game->player.posy \
		+ (int)(wolf_game->player.is_moving * wolf_game->player.roty * 10);
	j = -1;
	while (++j < 30)
	{
		i = -1;
		while (++i < 30)
		{
			if (wolf_game->tiles[j][i].block_player == 1 \
				&& p_nx > (10 * wolf_game->tiles[j][i].posx - 5) \
				&& p_nx < (10 * wolf_game->tiles[j][i].posx - 5) + 10 \
				&& p_ny > (10 * wolf_game->tiles[j][i].posy - 5) \
				&& p_ny < (10 * wolf_game->tiles[j][i].posy - 5) + 10)
				return (0);
		}
	}
	return (1);
}

static void		move_player(int d, t_wolf *wolf_game)
{
	if (d == 1)
	{
		wolf_game->player.posx += wolf_game->player.is_moving \
			* PLAYER_SPEED * wolf_game->player.rotx;
		wolf_game->player.posy += wolf_game->player.is_moving \
			* PLAYER_SPEED * wolf_game->player.roty;
	}
	else
	{
		wolf_game->player.posx -= wolf_game->player.is_moving \
			* PLAYER_SPEED * wolf_game->player.rotx;
		wolf_game->player.posy -= wolf_game->player.is_moving \
			* PLAYER_SPEED * wolf_game->player.roty;
	}
}

void			wolf_player_loop(t_wolf *wolf_game)
{
	if (wolf_game->player.is_moving != 0)
	{
		if (check_collisions(wolf_game) == 1)
			move_player(1, wolf_game);
		else
			move_player(-1, wolf_game);
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

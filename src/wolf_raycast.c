/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:07:01 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/04 14:06:35 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static void		check_border(double *x, double *y)
{
	if (*x < 0)
		*x = 0;
	else if (*x > WIN_WIDTH)
		*x = WIN_WIDTH;
	if (*y < 0)
		*y = 0;
	else if (*y > WIN_HEIGHT)
		*y = WIN_HEIGHT;
}

static int		check_wall(double x, double y, t_wolf *wolf_game)
{
	int j;
	int i;

	j = -1;
	while (++j < 64)
	{
		i = -1;
		while (++i < 64)
		{
			if (wolf_game->tiles[j][i].block_player == 1 \
				&& x > (10 * wolf_game->tiles[j][i].posx - 5) \
				&& x < (10 * wolf_game->tiles[j][i].posx - 5) + 10 \
				&& y > (10 * wolf_game->tiles[j][i].posy - 5) \
				&& y < (10 * wolf_game->tiles[j][i].posy - 5) + 10)
				return (0);
		}
	}
	return (1);
}

void			wolf_throwray(t_wolf *wolf_game)
{
	int i;
	double x;
	double y;

	i = -1;
	x = wolf_game->player.posx + 4 + 364;
	y = wolf_game->player.posy + 4 + 64;
	//while (++i < 20 && check_wall(x, y, wolf_game))
	while (++i < 200)
	{
		x += wolf_game->player.rotx * 2;
		y += wolf_game->player.roty * 2;
		check_border(&x, &y);
		wolf_game->smlx.imgstr[(int)x + ((int)y * WIN_WIDTH)] = 0x0000FF00;
	}
}

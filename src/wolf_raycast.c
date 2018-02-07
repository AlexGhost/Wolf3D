/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:07:01 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/07 16:29:23 by acourtin         ###   ########.fr       */
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
	if (wolf_game->collision[(int)y - 65][(int)x + 278] == 1)
		return (0);
	return (1);
}

int				wolf_throwray(double rot, t_wolf *wolf_game)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	x = wolf_game->player.posx + 4 + 364;
	y = wolf_game->player.posy + 4 + 64;
	rot -= 40.0;
	while (i < 30 && check_wall(x, y, wolf_game) == 1)
	{
		check_border(&x, &y);
		if (wolf_game->draw_minimap == 1)
			wolf_game->smlx.imgstr[(int)x + ((int)y * WIN_WIDTH)] = 0x0000FF00;
		x += sin(((wolf_game->player.rot - rot) / 180) * 3.14) * 2;
		y += cos(((wolf_game->player.rot - rot) / 180) * 3.14) * 2;
		i += 1;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/05 20:08:45 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int		inver(int n)
{
	long res;

	res = 0;
	while (n)
	{
		res += (res * 10) + n % 10;
		n /= 10;
	}
	return (res);
}

void			wolf_draw_wall(double col, int depth, t_wolf *wolf_game)
{
	int h;
	int l;
	int color;

	color = 0x00111111 * (depth / 10);
	h = -1;
	l = 0;
	while (++h < depth * 2)
	{
		l = -1;
		while (++l < 6)
			wolf_game->smlx.imgstr[(int)(col * 15.5) + l + ((h + 400 - (depth * 1)) \
				* WIN_WIDTH)] = color;
	}
}

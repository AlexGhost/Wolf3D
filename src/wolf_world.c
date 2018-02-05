/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/05 11:48:25 by acourtin         ###   ########.fr       */
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

void			wolf_draw_wall(int col, int depth, t_wolf *wolf_game)
{
	int h;
	int l;
	int color;

	color = 0x00111111 * (depth / 10);
	h = -1;
	l = 0;
	col += 45;
	while (++h < depth * 2)
	{
		l = -1;
		while (++l < 15)
			wolf_game->smlx.imgstr[((int)col * 15) + 15 + l + ((h + 300 - (depth * 1)) \
				* WIN_WIDTH)] = color;
	}
}

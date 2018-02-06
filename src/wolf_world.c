/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/06 16:45:40 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int		inver(int n)
{
	int tab[31];
	int i;
	int j;

	i = 0;
	j = 30;
	while (i <= 30)
	{
		tab[i] = j;
		i++;
		j--;
	}
	return (tab[n]);
}

void			wolf_draw_wall(double col, int depth, t_wolf *wolf_game)
{
	int h;
	int l;
	int color;

	depth = inver(depth);
	color = 0x00111111 * (depth / 5);
	h = -1;
	l = 0;
	while (++h < (depth * 5))
	{
		l = -1;
		while (++l < 7)
			wolf_game->smlx.imgstr[(int)(col * 17.5) + l + ((h + 400 - depth) \
				* WIN_WIDTH)] = color;
	}
}

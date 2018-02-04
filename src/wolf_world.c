/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:21 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/04 17:46:58 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void			wolf_draw_wall(double col, int depth, t_wolf *wolf_game)
{
	int h;
	int l;

	h = -1;
	while (++h < 100)
	{
		l = -1;
		while (++l < 1000)
		{
			wolf_game->smlx.imgstr[(int)col + 90 + l + (h * WIN_WIDTH)] = (depth / 5) * 0x00111111;
		}
	}
}

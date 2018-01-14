/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:32 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 16:47:47 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int				wolf_exit(void)
{
	ft_putendl("wolf3d shutting down");
	exit(0);
	return (0);
}

static void		window_init(t_mlx *smlx, t_img *i)
{
	smlx->mlx = mlx_init();
	smlx->win = mlx_new_window(smlx->mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3d");
	smlx->img = mlx_new_image(smlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	smlx->imgstr = (int*)mlx_get_data_addr(smlx->img, &i->bpp, &i->s_l, \
			&i->endian);
}

void			wolf_create_window(t_wolf *wolf_game)
{
	t_img		i;

	window_init(&wolf_game->smlx, &i);
	mlx_hook(wolf_game->smlx.win, 17, 0, wolf_exit, 0);
	mlx_hook(wolf_game->smlx.win, 2, 0, wolf_keypress_event, (void*)wolf_game);
	mlx_hook(wolf_game->smlx.win, 3, 0, wolf_keyrelease_event, \
			(void*)wolf_game);
	mlx_loop_hook(wolf_game->smlx.mlx, wolf_draw_minimap, (void*)wolf_game);
	mlx_loop(wolf_game->smlx.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:40 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 18:39:11 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "fcntl.h"
# include "wolf_mlx.h"
# include "wolf_button.h"

# define PLAYER_SPEED 0.1

typedef enum		e_tiles_type
{
	TILE_FLOOR = 1,
	TILE_WALL = 2
}					t_tiles_type;

typedef enum		e_directions
{
	LEFT = 1,
	UP = 2,
	RIGHT = 3,
	DOWN = 4
}					t_directions;

typedef struct		s_player
{
	double			posx;
	double			posy;
	double			rot;
	int				movex;
	int				movey;
}					t_player;

typedef struct		s_tile
{
	int				type;
	int				posx;
	int				posy;
	int				block_player;
}					t_tile;

typedef struct		s_wolf
{
	t_mlx			smlx;
	t_player		player;
	t_tile			tiles[30][30];
}					t_wolf;

void				wolf_create_window(t_wolf *wolf_game);
void				wolf_player_loop(t_wolf *wolf_game);
void				wolf_player_init(t_wolf *wolf_game);
int					wolf_loadmap(char *mapfile, t_wolf *wolf_game);
int					wolf_draw_minimap(t_wolf *wolf_game);
int					wolf_exit(void);
int					wolf_keypress_event(int keycode, t_wolf *wolf_game);
int					wolf_keyrelease_event(int keycode, t_wolf *wolf_game);

#endif

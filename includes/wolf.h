/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:40 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/14 17:30:07 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "fcntl.h"
# include "wolf_button.h"

# define WIN_WIDTH 1400
# define WIN_HEIGHT 800
# define PLAYER_SPEED 0.3

typedef enum		e_tiles_type
{
	TILE_FLOOR = 1,
	TILE_WALL = 2
}					t_tiles_type;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*imgstr;
}					t_mlx;

typedef struct		s_img
{
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

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

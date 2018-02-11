/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:40 by acourtin          #+#    #+#             */
/*   Updated: 2018/02/11 21:02:44 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "math.h"
# include "fcntl.h"
# include "wolf_mlx.h"
# include "wolf_button.h"
# include "wolf_colors.h"

# define PLAYER_SPEED 1
# define PLAYER_TURN_RATE 2
# define GUN_FIRERATE 0.5
# define OZ_DEPLETE 0.1
# define OZ_REFILL 0.3

typedef enum		e_tiles_type
{
	TILE_FLOOR = 1,
	TILE_WALL = 2,
	TILE_SPACE = 3,
	TILE_SAS = 4
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
	double			rotx;
	double			roty;
	double			rot;
	float			oxygen;
	float			fire_timer;
	float			head_bob;
	int				head_trmble;
	int				is_moving;
	int				is_rot;
	int				is_firing;
}					t_player;

typedef struct		s_tile
{
	int				type;
	int				posx;
	int				posy;
	int				block_player;
	int				have_atmo;
}					t_tile;

typedef struct		s_xpm
{
	void			*img;
	int				width;
	int				height;
	int				*imgstr;
	t_img			simg;
}					t_xpm;

typedef struct		s_hitbox
{
	int				collision;
	int				oxygen;
}					t_hitbox;

typedef struct		s_wolf
{
	t_mlx			smlx;
	t_player		player;
	t_tile			tiles[64][64];
	t_hitbox		hitbox[641][641];
	double			player_spawn_x;
	double			player_spawn_y;
	int				draw_minimap;
	int				draw_wep;
	t_xpm			xpm_skybox;
	t_xpm			xpm_gun_idle;
	t_xpm			xpm_gun_fire;
}					t_wolf;

void				wolf_create_window(t_wolf *wolf_game);
void				wolf_player_loop(t_wolf *wolf_game);
void				wolf_player_init(t_wolf *wolf_game);
void				wolf_world_init(t_wolf *wolf_game);
void				wolf_draw_hud(t_wolf *wolf_game);
void				wolf_draw_skybox(t_wolf *wolf_game);
void				wolf_draw_wall(double col, int depth, t_wolf *wolf_game);
void				wolf_firegun(t_wolf *wolf_game);
int					wolf_loadmap(char *mapfile, t_wolf *wolf_game);
int					wolf_draw_minimap(t_wolf *wolf_game);
int					wolf_exit(void);
int					wolf_keypress_event(int keycode, t_wolf *wolf_game);
int					wolf_keyrelease_event(int keycode, t_wolf *wolf_game);
int					wolf_throwray(double rot, t_wolf *wolf_game);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:17:40 by acourtin          #+#    #+#             */
/*   Updated: 2018/01/13 18:33:18 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "fcntl.h"

# define WIN_WIDTH 1400
# define WIN_HEIGHT 800
# define BUTTON_ESCAPE 53
# define BUTTON_W 13
# define BUTTON_D 2
# define BUTTON_S 1
# define BUTTON_A 0
# define BUTTON_Q 12
# define BUTTON_E 14
# define BUTTON_B 11
# define BUTTON_C 8
# define BUTTON_ARROW_UP 126
# define BUTTON_ARROW_RIGHT 124
# define BUTTON_ARROW_DOWN 125
# define BUTTON_ARROW_LEFT 123
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_WHEEL_UP 5
# define MOUSE_WHEEL_DOWN 4

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

typedef struct		s_wolf
{
	t_mlx			smlx;
	char			tiles[50][50];
}					t_wolf;

void				wolf_create_window(t_wolf *wolf_game);
int					wolf_loadmap(char *mapfile, char tiles[50][50]);

#endif

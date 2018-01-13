#ifndef WOLF_H
# define WOLF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>

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

void				wolf_create_window(void);

#endif
#include "../includes/wolf.h"

static int		exitwolf(void)
{
	ft_putendl("wolf3d shutting down");
	exit(0);
	return (0);
}

static int		keyevent(int keycode)
{
	ft_putstr("Button pressed : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == BUTTON_ESCAPE)
		exitwolf();
	return (0);
}

static void		window_init(t_mlx *smlx, t_img *i)
{
	smlx->mlx = mlx_init();
	smlx->win = mlx_new_window(smlx->mlx, WIN_WIDTH, WIN_HEIGHT, "wolf3D");
	smlx->img = mlx_new_image(smlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	smlx->imgstr = (int*)mlx_get_data_addr(smlx->img, &i->bpp, &i->s_l, \
			&i->endian);
}

void			wolf_create_window(void)
{
	t_mlx		smlx;
	t_img		i;

	window_init(&smlx, &i);
	mlx_key_hook(smlx.win, keyevent, 0);
	mlx_hook(smlx.win, 17, 0, exitwolf, 0);
	mlx_loop(smlx.mlx);
}

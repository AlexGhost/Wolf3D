#include "../includes/wolf.h"

static void		write_usage(void)
{
	ft_putendl("usage: ./fractol <mode>");
	ft_putendl("\tmode 1 : Mandelbrot");
	ft_putendl("\tmode 2 : Julia");
	ft_putendl("\tmode 3 : BurningShip");
	exit(0);
}

int				main(int ac, char **av)
{
	wolf_create_window();
	return (0);
}
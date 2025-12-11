
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_window	window;

	ft_memset(&mlx, 0, sizeof(mlx));
	ft_memset(&window, 0, sizeof(window));
	open_window(&mlx);
	close_window(&mlx);
	return (0);
}
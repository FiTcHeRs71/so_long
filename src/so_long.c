
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_window	window;

	if (argc < 0)
	{
		ft_printf("%s", argv[0]);
		return(0); // a check
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	ft_memset(&window, 0, sizeof(window));
	init_data(&mlx);
	handle_window(&mlx);
	//close_window(&mlx);
	return (0);
} 
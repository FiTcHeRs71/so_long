
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;

	if (argc < 0)
	{
		ft_printf("%s", argv[0]);
		return(0); // a check
	}
	ft_memset(&mlx, 0, sizeof(mlx));
	init_data(&mlx, argv);
	handle_window(&mlx);
	load_textures(&mlx);
	set_up_map(&mlx);
	mlx_loop(mlx.mlx_connect);

	//close_window(&mlx);
	return (0);
}

// free file dans init data
// close file dans init data

#include "../include/so_long.h"

void	open_window(t_mlx *mlx)
{
	mlx->mlx_connection = mlx_init();
	if (!mlx->mlx_connection)
	{
		// ft_error ?
		exit(EXIT_FAILURE);
	}
	mlx->mlx_window = mlx_new_window(mlx->mlx_connection, WIDTH, HEIGHT, "Fitch > Leo");
	if (!mlx->mlx_window)
	{
		// ft_error, free ?
		close_window(mlx);

	}
}

void	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_connection, mlx->mlx_window);
	mlx_destroy_display(mlx->mlx_connection);
	free(mlx->mlx_connection); // a ranger autre part ?
}
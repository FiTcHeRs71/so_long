
#include "../include/so_long.h"

void	handle_window(t_mlx *mlx)
{
	mlx->mlx_connection = mlx_init();
	if (!mlx->mlx_connection)
	{
		// ft_error ?
		exit(EXIT_FAILURE);
	}
	mlx->mlx_window = mlx_new_window(mlx->mlx_connection, WIDTH, HEIGHT,
			"Fitch > Leo sur MK");
	if (!mlx->mlx_window)
	{
		// ft_error, free ?
		close_window(mlx);
	}
	mlx_key_hook(mlx->mlx_window, handle_keyboard_input, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
	mlx_mouse_hook(mlx->mlx_window, handle_mouse_input, mlx);
	mlx_loop(mlx->mlx_connection);
}

int	handle_keyboard_input(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		ft_printf("%d (Esc)touch press\n\n", keycode);
		close_window(mlx);
	}
	ft_printf("%d touch press\n\n", keycode);
	return (0);
}

int	*handle_mouse_input(void)
{
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_connection, mlx->mlx_window);
	mlx_destroy_display(mlx->mlx_connection);
	free(mlx->mlx_connection); // a ranger autre part ?
	exit(EXIT_SUCCESS);        // succes ?
}

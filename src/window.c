
#include "../include/so_long.h"

void	handle_window(t_mlx *mlx)
{
	mlx->mlx_connect = mlx_init();
	if (!mlx->mlx_connect)
	{
		// ft_error ?
		exit(EXIT_FAILURE);
	}
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, mlx->window.size_x, mlx->window.size_y, "Fitch > Leo sur MK");
	if (!mlx->mlx_window)
	{
		// ft_error, free ?
		close_window(mlx);
	}
	mlx_key_hook(mlx->mlx_window, handle_keyboard_input, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, mlx->tex.esc, 0, 0);
}
int	handle_keyboard_input(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		ft_printf("%d Esc pressed - closing window\n", keycode);
		close_window(mlx);
	}
	ft_printf("%d touch press\n\n", keycode);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_connect, mlx->mlx_window);
	mlx_destroy_display(mlx->mlx_connect);
	free(mlx->mlx_connect); // a ranger autre part ?
	exit(EXIT_SUCCESS);     // succes ?
}

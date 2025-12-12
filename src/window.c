
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
}
int	handle_keyboard_input(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{	
		ft_printf("%d Esc pressed - closing window\n", keycode);
		close_window(mlx);
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		ft_printf("w");
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		ft_printf("a");
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		ft_printf("s");
	}
		if (keycode == XK_d || keycode == XK_Right)
	{
		ft_printf("d");
	}
	ft_printf("%d", keycode);
	return (0);
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_connect, mlx->mlx_window);
	mlx_destroy_display(mlx->mlx_connect);
	free(mlx->mlx_connect); // a ranger autre part ?
	exit(EXIT_SUCCESS);     // succes ?
}

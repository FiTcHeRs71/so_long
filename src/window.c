
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
	//mlx->img.img_ptr = mlx_new_image(mlx->mlx_connect, WIDTH, HEIGHT);
	//mlx->img.pxl_ptr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits, &mlx->img.len, &mlx->img.endlian);
	//mlx_put_image_to_window(mlx, mlx->mlx_window, mlx->img.img_ptr, 0, 0);
	mlx_key_hook(mlx->mlx_window, handle_keyboard_input, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
	mlx_loop(mlx->mlx_connect);
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

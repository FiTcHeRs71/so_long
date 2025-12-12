else if (keycode == 65451)
{
	resize_window(mlx, mlx->window.size_x + 100, mlx->window.size_y + 100);
}
else if (keycode == 65453)
{
	resize_window(mlx, mlx->window.size_x - 100, mlx->window.size_y - 100);
}
else if (keycode == XK_r)
{
	color_screen(mlx, 0xff0000);
}
else if (keycode == XK_g)
{
	color_screen(mlx, 0xff00);
}
else if (keycode == XK_b)
{
	color_screen(mlx, 0xff);
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

void	color_screen(t_mlx *mlx, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_pixel_put(&mlx->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, mlx->img.img_ptr,
		0, 0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->len * y) + (x * (img->bits / 8));
	*((unsigned int *)(offset + img->pxl_ptr)) = color;
}

void	resize_window(t_mlx *mlx, int new_width, int new_height)
{
	if (new_width < mlx->window.min_width)
		new_width = mlx->window.min_width;
	if (new_width > mlx->window.max_width)
		new_width = mlx->window.max_width;
	if (new_height < mlx->window.min_height)
		new_height = mlx->window.min_height;
	if (new_height > mlx->window.max_height)
		new_height = mlx->window.max_height;
	mlx_destroy_window(mlx->mlx_connect, mlx->mlx_window);
	mlx->window.size_x = new_width;
	mlx->window.size_y = new_height;
	mlx->mlx_window = mlx_new_window(mlx->mlx_connect, new_width, new_height,
			"So Long - Pokémon Style");
	if (!mlx->mlx_window)
	{
		// ft_error, free ?
		close_window(mlx);
	}
	mlx_key_hook(mlx->mlx_window, handle_keyboard_input, mlx);
	mlx_hook(mlx->mlx_window, 17, 0, close_window, mlx);
}

mlx->tex.esc = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/esc.xpm", &mlx->tex.width, &mlx->tex.height);
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, mlx->tex.esc, 0, 0);
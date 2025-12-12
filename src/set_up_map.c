
#include "../include/so_long.h"

void	set_up_map(t_mlx *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_connect, WIDTH, HEIGHT);
	mlx->img.pxl_ptr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits, &mlx->img.len, &mlx->img.endlian);
	//mlx_put_image_to_window(mlx, mlx->mlx_window, mlx->img.img_ptr, 0, 0);
}
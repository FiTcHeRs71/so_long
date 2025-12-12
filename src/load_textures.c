
#include "../include/so_long.h"

void	load_textures(t_mlx *mlx)
{
	mlx->tex.grass = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/grass.xpm", &mlx->tex.width, &mlx->tex.height);
	mlx->tex.tree = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/tree.xpm", &mlx->tex.width, &mlx->tex.height);
	mlx->tex.player = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/player.xpm", &mlx->tex.width, &mlx->tex.height);
	mlx->tex.esc = mlx_xpm_file_to_image(mlx->mlx_connect, "texture/esc.xpm", &mlx->tex.width, &mlx->tex.height);
}
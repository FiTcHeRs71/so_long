
#include "../include/so_long.h"

void	set_up_map(t_mlx *mlx, char **argv)
{
	int 	fd;
	char	*line;
	int		y;

	fd = open(argv[1], O_RDONLY);
	y = 0;
	while ((line = get_next_line(fd)))
	{
		render_line(line, mlx, y);
		y++;
		free(line);
	}
	free(line);
}

void	render_line(char *line, t_mlx *mlx, int y)
{
	int	x;

	x = 0;
	while(line[x] && line[x] != '\n')
	{
		draw_with_img(mlx, line[x], x, y);
		x++;
	}
}

void	draw_with_img(t_mlx *mlx, char c, int x, int y)
{
	void	*texture;
	if (c == '1')
	{
		texture = mlx->tex.tree;
	}
	else if (c == '0')
	{
		texture = mlx->tex.grass;
	}
	else if (c == 'E')
	{
		texture = mlx->tex.esc;
	}
	else if (c == 'C')
	{
		texture = mlx->tex.eat;
	}
	else if (c == 'P')
	{
		texture = mlx->tex.player;
	}
	else
	{
		texture = mlx->tex.grass;
	}
	mlx_put_image_to_window(mlx->mlx_connect, mlx->mlx_window, texture, x * 64, y * 64);
}

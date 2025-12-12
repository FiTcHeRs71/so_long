
#include "../include/so_long.h"

void	init_data(t_mlx *mlx, char **argv)
{
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))== NULL)
	{
		//ft_error ( map has to be .ber)
	}
	mlx->fd = open(argv[1], O_RDONLY);
	check_map(t_mlx);
	if (mlx->fd < 0)
	{
		//ft_error, free
	}
	mlx->window.size_x = count_rows(mlx->fd) * 64; // check invalid map ?
	mlx->window.size_y = count_line(mlx->fd) * 64;
}
int	count_rows(int fd)
{
	char	*line;
	int		size_x;

	line = get_next_line(fd);
	size_x = ft_strlen(line);
	free(line);
	return(size_x - 1);
}
int	count_line(int fd)
{
	char	*line;
	int		size_y;

	line = get_next_line(fd);
	size_y = 0;
	while(line)
	{
		size_y += 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return(size_y + 1);
}
void	check_map(t_mlx *mlx)
{
	
}

#include "../include/so_long.h"

void	init_data(t_mlx *mlx, char **argv)
{
	int	fd;

	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1]))== NULL)
	{
		//ft_error ( map has to be .ber)
	}
	fd = open(argv[1], O_RDONLY);	
	if (fd < 0)
	{
		//ft_error, free
	}
	mlx->args = fill_args(fd);
	check_map(mlx, mlx->args);
	mlx->window.size_x = (ft_strlen(mlx->args[0])) * 64;
	mlx->window.size_y = count_line(mlx->args) * 64;
}
int	count_line(char	**args)
{
	size_t	i;
	int		size_y;

	i = 0;
	size_y = 0;
	while(args[i])
	{
		size_y += 1;
		i++;
	}
	return(size_y);
}

char	**fill_args(int fd)
{
	char	*line;
	char	*temp;
	char	**args;

	temp = ft_strdup("");
	line = get_next_line(fd);
	while(line)
	{
		temp = ft_strjoin(temp, line);
		free(line);
		line = get_next_line (fd);
	}
	args = ft_split(temp, '\n');
	free(temp);
	return (args);
}

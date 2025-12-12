
#include "../include/so_long.h"

void	check_map(t_mlx *mlx,char **args)
{
	size_t	i;
	int		size;

	i = 0;
	mlx->len = ft_strlen(args[0]);
	while(args[i])
	{
		check_arg(args[i]);
		size = ft_strlen(args[i]);
		if (mlx->len != size)
		{
			//ft _error
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
void	check_arg(char	*line)
{
	size_t	i;

	i = 0;
	line = ft_strtrim(line, "\n");
	while(line[i])
	{
		if (!ft_isascii(line[i]))
		{
			//ft _error
			exit(EXIT_FAILURE);
		}
		if (!ft_strchr("10EPC", line[i]))
		{
			//ft _error
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
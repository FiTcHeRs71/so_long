
#include "../include/so_long.h"

void	check_map(t_mlx *mlx,char **args)
{
	size_t	i;
	int		size;

	i = 0;
	mlx->len = ft_strlen(args[0]);
	while(args[i])
	{
		check_arg(args[i], mlx);
		size = ft_strlen(args[i]);
		if (mlx->len != size)
		{
			//ft _error
			exit(EXIT_FAILURE);
		}
		i++;
	}
	check_flag(mlx);
}
void	check_arg(char	*line, t_mlx *mlx)
{
	size_t	i;

	i = 0;
	line = ft_strtrim(line, "\n");
	while(line[i])
	{		if (!ft_isascii(line[i]))
		{
			//ft _error
			exit(EXIT_FAILURE);
		}
		if (!ft_strchr("10EPC", line[i]))
		{
			//ft _error
			exit(EXIT_FAILURE);
		}
		ft_count_and_check_args(line[i], mlx);
		i++;
	}
}
void	ft_count_and_check_args(char c, t_mlx *mlx) // struct 
{
	if(c == 'P')
	{
		mlx->flag_p += 1;
	}
	if(c == 'E')
	{
		mlx->flag_e += 1;
	}
	if (c == 'C')
	{
		mlx->flag_c += 1;
	}
}

void	check_flag(t_mlx *mlx)
{
	if (mlx->flag_c == 0)
	{
		// need manger
		exit (EXIT_FAILURE);
	}
	if (mlx->flag_e > 1)
	{
		//trop d'exit
		exit (EXIT_FAILURE);
	}
	if (mlx->flag_p > 1)
	{
		// trop de player
		exit(EXIT_FAILURE);
	}
}


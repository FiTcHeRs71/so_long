#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

typedef struct s_mlx
{
	void	*mlx_connection;
	void	*mlx_window;
}			t_mlx;

typedef struct s_window
{
	int		sixe_x;
	int		size_y;
}			t_window;

#endif
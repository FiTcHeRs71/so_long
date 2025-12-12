#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bits;
	int		endlian;
	int		len;
}			t_img;

	typedef struct s_window
{
	int			size_x;
	int			size_y;
	int			min_width;
	int			min_height;
	int			max_width;
	int			max_height;
}				t_window;

typedef struct s_mlx
{
	void		*mlx_connect;
	void		*mlx_window;
	t_window	window;
	t_img		img;
}				t_mlx;

#endif
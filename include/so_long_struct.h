#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

typedef struct s_tex
{
	void	*tree;
	void	*grass;

}	t_tex;

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
}				t_window;

typedef struct s_mlx
{
	void		*mlx_connect;
	void		*mlx_window;
	t_window	window;
	t_img		img;
	t_tex		tex;
}				t_mlx;

#endif
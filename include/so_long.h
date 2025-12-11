#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "so_long_struct.h"
# include "../minilibx-linux/mlx.h"

# define	WIDTH	400
# define	HEIGHT	400

/* window.c */
void	close_window(t_mlx *mlx);
void	open_window(t_mlx *mlx);

#endif
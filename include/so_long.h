#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "so_long_struct.h"
# include <X11/keysym.h>

# define WIDTH 1500
# define HEIGHT 1000

/* window.c */
void	handle_window(t_mlx *mlx);
int		handle_keyboard_input(int keycode, t_mlx *mlx);
int		close_window(t_mlx *mlx);


#endif
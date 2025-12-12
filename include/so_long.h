#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "so_long_struct.h"
# include <X11/keysym.h>

# define WIDTH 900
# define HEIGHT 700
/* # define MIN_WIDTH 800
# define MIN_HEIGHT 600
# define MAX_WIDTH 4000
# define MAX_HEIGHT 2000 */

/* window.c */
void	handle_window(t_mlx *mlx);
int		handle_keyboard_input(int keycode, t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	resize_window(t_mlx *mlx, int new_width, int new_height);
void	color_screen(t_mlx *mlx, int color);
void	my_pixel_put(t_img *img, int x, int y, int color);

/* init_data.c */
void init_data(t_mlx *mlx);

/* set_up_map.c */
void	set_up_map(t_mlx *mlx);

#endif
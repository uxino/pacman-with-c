/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:54:36 by museker           #+#    #+#             */
/*   Updated: 2023/09/03 15:30:26 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <math.h>

typedef struct map_values{
	int		mapsize_x;
	int		mapsize_y;
	int		c;
	int		e;
	int		p;
	int		m;
	int		enemy_i;
	int		enemy_j;
	int		e_x;
	int		e_y;
	int		ch_i;
	int		ch_j;
	char	**map;
}	t_map_info;

typedef struct images
{
	void	*empty;
	void	*wall;
	void	*coin;
	void	*ch;
	void	*ball;
	void	*portal;
	void	*portal_ch;
	void	*enemy; 
}	t_map_images;

typedef struct character
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	is_finish;
	int	alive;
}	t_pacman;

typedef struct s_point
{
	int			x;
	int			y;
}				t_fill_point;

typedef struct total_structs
{
	void			*mlx;
	void			*win;
	t_pacman		*ch;
	t_map_images	*map_img;
	t_map_info		*map;
	int				animate_count;
	void			*animate;
}	t_struct_control;

// main.c
int					key_code(int keycode, t_struct_control *stc);
void				error_message(char *str);

// utils/put_image.c
t_struct_control	*images(t_struct_control *stc);
void				put_image(t_struct_control *stc);
void				put_image2(t_struct_control *stc, char map_c, 
						int *coordinate, int *coin);
void				put_image3(t_struct_control *stc, int i, 
						int j, int *coordinate);
int					portal_and_check_img(t_struct_control *stc, int i, 
						int j, int *step_count);
void				map_refresh(t_struct_control *stc);

// utils/charact	er_controller.c
int					all2(t_struct_control *stc, int i, int j);
void				key_left(t_struct_control *stc);
void				key_right(t_struct_control *stc);
void				key_up(t_struct_control *stc);
void				key_down(t_struct_control *stc);

// utils/ft_prin	tf.c
void				ft_putchar(char c);
void				ft_putnbr(int nb);
void				ft_putstr(char *str);
void				arg_check(va_list lst, char c);
void				ft_printf(const char *str, ...);

// utils/check_m	ap.c
t_map_info			*rectangle_control(t_map_info *map, char *map_name);
void				wall_control(t_map_info *map);
void				check_value(t_map_info *map, int i, int j);
t_map_info			*check_map(char *map_name);

// utils/map_validation.c
void				fill(char **tab, t_fill_point size, t_fill_point cur, 
						char to_fill);
void				flood_fill(char **tab, t_fill_point size, 
						t_fill_point begin);
char				**paint_map(t_map_info *map);
void				is_reachable(t_map_info *map, char **clone_map);
void				map_validation(t_map_info *map);

// extra	
char				*ft_itoa(int n);
void				ghost_movement(t_struct_control *stc);
void				mucox18_step_count(t_struct_control *stc, int i);
void				exit_control(t_map_info *map);

// animation
void				coin_loop(t_struct_control *game);
int					loop(t_struct_control *game);

#endif

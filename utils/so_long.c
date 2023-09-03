/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:51:44 by museker           #+#    #+#             */
/*   Updated: 2023/09/03 16:12:27 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_printf("Error: %s\n", str);
	exit(0);
}

int	key_code(int keycode, t_struct_control *stc)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 0)
		key_left(stc);
	else if (keycode == 1)
		key_down(stc);
	else if (keycode == 2)
		key_right(stc);
	else if (keycode == 13)
		key_up(stc);
	return (0);
}

void	exit_control(t_map_info *map)
{
	if (map->map[map->e_x - 1][map->e_y] == '1' && 
	map->map[map->e_x + 1][map->e_y] == '1' 
	&& map->map[map->e_x][map->e_y + 1] == '1' && 
	map->map[map->e_x][map->e_y - 1] == '1')
		error_message("not a valid map");
}

int	close_game(void *param)
{
	param = NULL;
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_struct_control	*stc;

	if (argc != 2)
		error_message("Eksik argüman!");
	stc = malloc(sizeof(t_struct_control));
	stc->ch = malloc(sizeof(t_pacman));
	stc->mlx = mlx_init();
	stc->map = check_map(argv[1]);
	exit_control(stc->map);
	map_validation(stc->map);
	stc->win = mlx_new_window(stc->mlx, stc->map->mapsize_y * 50,
			stc->map->mapsize_x * 50, "so_long");
	stc = images(stc);
	put_image(stc);
	mlx_hook(stc->win, 2, 1L << 0, key_code, stc);
	mlx_hook(stc->win, 17, 0L, close_game, NULL);
	mlx_loop_hook(stc->mlx, loop, stc);
	mlx_loop(stc->mlx);
	return (0);
}

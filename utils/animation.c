/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:09:13 by museker           #+#    #+#             */
/*   Updated: 2023/09/03 15:24:10 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_loop(t_struct_control *game)
{
	int	w;

	mlx_clear_window(game->mlx, game->win);
	w = 64;
	if (game->animate_count == 0)
		game->animate = \
			mlx_xpm_file_to_image(game->mlx, "./textures/portal.xpm", &w, &w);
	else if (game->animate_count == 10)
		game->animate = \
			mlx_xpm_file_to_image(game->mlx, "./textures/l_p.xpm", &w, &w);
	else if (game->animate_count == 20)
		game->animate = \
			mlx_xpm_file_to_image(game->mlx, "./textures/portal.xpm", &w, &w);
	else if (game->animate_count == 30)
		game->animate = \
			mlx_xpm_file_to_image(game->mlx, "./textures/l_p.xpm", &w, &w);
	else if (game->animate_count >= 40)
	{
		game->animate = \
			mlx_xpm_file_to_image(game->mlx, "./textures/portal.xpm", &w, &w);
		game->animate_count = 0;
	}
	put_image(game);
	game->animate_count += 1;
}

int	loop(t_struct_control *game)
{
	coin_loop(game);
	mucox18_step_count(game, 0);
	return (1);
}

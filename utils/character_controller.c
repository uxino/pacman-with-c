/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:38:25 by museker           #+#    #+#             */
/*   Updated: 2023/08/21 19:11:21 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all(t_struct_control *stc, int i, int j, char *path)
{
	static int	step_count = 1;
	int			px; 
	int			py;

	ghost_movement(stc);
	if (portal_and_check_img(stc, i, j, &step_count) == 31)
	{
		return (0);
	}
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'M')
	{
		ft_printf("you died!");
		exit(31);
	}
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == '0' 
		|| stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'C')
	{
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		stc->map_img->ch = mlx_xpm_file_to_image(stc->mlx, path, &px, &py);
		map_refresh(stc);
		mucox18_step_count(stc, 1);
	}
	return (0);
}

void	key_left(t_struct_control *stc)
{
	all(stc, 0, -1, "textures/chL.xpm");
}

void	key_right(t_struct_control *stc)
{
	all(stc, 0, 1, "textures/chR.xpm");
}

void	key_up(t_struct_control *stc)
{
	all(stc, -1, 0, "textures/chT.xpm");
}

void	key_down(t_struct_control *stc)
{
	all(stc, 1, 0, "textures/chB.xpm");
}

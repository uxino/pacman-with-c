/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:44:37 by museker           #+#    #+#             */
/*   Updated: 2023/08/21 19:35:48 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	abc(t_struct_control *stc, int i, int j)
{
	if (stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] != '1'
		&& stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] != 'P'
		&& stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] != 'X'
		&& stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] != 'E'
		&& stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] != 'C')
	{
		stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] = 'M';
		stc->map->map[stc->map->enemy_i][stc->map->enemy_j] = '0';
		stc->map->enemy_i += i;
		stc->map->enemy_j += j;
		map_refresh(stc);
	}
	return (31);
}

void	ghost_movement(t_struct_control *stc)
{
	int	a;

	a = rand() % 4;
	if (a == 0)
		abc(stc, 0, -1);
	else if (a == 1)
		abc(stc, 0, 1);
	else if (a == 2)
		abc (stc, -1, 0);
	else
		abc (stc, 1, 0);
}

void	mucox18_step_count(t_struct_control *stc, int i)
{
	static int	step_count = 1;
	char		*s;

	s = ft_itoa(step_count);
	mlx_string_put(stc->mlx, stc->win, 8, 15, 255, "Step Count: ");
	mlx_string_put(stc->mlx, stc->win, 10, 30, 255, s);
	if (i == 1)
		step_count++;
	free(s);
}

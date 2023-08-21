/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:50:42 by museker           #+#    #+#             */
/*   Updated: 2023/08/21 19:15:41 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_fill_point size, t_fill_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == to_fill)
		return ;
	tab[cur.y][cur.x] = '1';
	fill(tab, size, (t_fill_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_fill_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_fill_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_fill_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_fill_point size, t_fill_point begin)
{
	fill(tab, size, begin, '1');
}

char	**paint_map(t_map_info *map)
{
	char	**clone_map;
	int		i;
	int		j;

	i = 0;
	clone_map = malloc(sizeof(char **) * map->mapsize_x);
	while (i < map->mapsize_x)
	{
		j = 0;
		clone_map[i] = malloc(sizeof(char *) * map->mapsize_y);
		while (j < map->mapsize_y)
		{
			clone_map[i][j] = map->map[i][j];
			if (map->map[i][j] == 'P' 
				|| map->map[i][j] == 'E' || map->map[i][j] == 'M')
				clone_map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (clone_map);
}

void	is_reachable(t_map_info *map, char **clone_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->mapsize_x)
	{
		j = 0;
		while (j < map->mapsize_y)
		{
			if (clone_map[i][j] == 'C')
				error_message("Map ulaşılabilir değil!");
			j++;
		}
		free(clone_map[i]);
		i++;
	}
	free(clone_map);
}

void	map_validation(t_map_info *map)
{
	char			**clone_map;
	t_fill_point	size;
	t_fill_point	begin;

	size.x = map->mapsize_y;
	size.y = map->mapsize_x;
	begin.x = map->ch_j;
	begin.y = map->ch_i;
	clone_map = paint_map(map);
	flood_fill(clone_map, size, begin);
	is_reachable(map, clone_map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:51:38 by museker           #+#    #+#             */
/*   Updated: 2023/09/03 14:44:22 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_struct_control	*images(t_struct_control *stc)
{
	int	pixel_x;
	int	pixel_y;

	stc->map_img = malloc(sizeof(t_map_images));
	stc->map_img->empty = mlx_xpm_file_to_image(stc->mlx, "textures/empty.xpm", 
			&pixel_x, &pixel_y);
	stc->map_img->wall = mlx_xpm_file_to_image(stc->mlx, "textures/wall.xpm", 
			&pixel_x, &pixel_y);
	stc->map_img->coin = mlx_xpm_file_to_image(stc->mlx, "textures/coin.xpm", 
			&pixel_x, &pixel_y);
	stc->map_img->ch = mlx_xpm_file_to_image(stc->mlx, "textures/chR.xpm", 
			&pixel_x, &pixel_y);
	stc->animate = mlx_xpm_file_to_image(stc->mlx, 
			"textures/portal.xpm", &pixel_x, &pixel_y);
	stc->map_img->portal_ch = mlx_xpm_file_to_image(stc->mlx, 
			"textures/portalCh.xpm", &pixel_x, &pixel_y);
	stc->map_img->enemy = mlx_xpm_file_to_image(stc->mlx, "textures/enemy.xpm", 
			&pixel_x, &pixel_y);
	return (stc);
}

void	put_image(t_struct_control *stc)
{
	int	i;
	int	j;
	int	coordinate[2];
	int	coin;

	i = -1;
	coordinate[1] = 0;
	coin = 0;
	while (++i < stc->map->mapsize_x)
	{
		j = -1;
		coordinate[0] = 0; 
		while (stc->map->map[i][++j] != '\0')
		{
			put_image2(stc, stc->map->map[i][j], coordinate, &coin);
			put_image3(stc, i, j, coordinate);
			coordinate[0] += 50;
		}
		coordinate[1] += 50;
	}
	stc->ch->is_finish = 0;
	if (coin == 0)
		stc->ch->is_finish = 1;
}

void	put_image2(t_struct_control *stc, char map_c, int *coordinate, 
int *coin)
{
	if (map_c == '1')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->wall, 
			coordinate[0], coordinate[1]);
	else if (map_c == '0')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->empty,
			coordinate[0], coordinate[1]);
	else if (map_c == 'C')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->coin, 
			coordinate[0], coordinate[1]);
		*coin += 1;
	}
	else if (map_c == 'E')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->animate, 
			coordinate[0], coordinate[1]);
	}
	else if (map_c == 'M')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->enemy, 
			coordinate[0], coordinate[1]);
}

void	put_image3(t_struct_control *stc, int i, int j, int *coordinate)
{
	if (stc->map->map[i][j] == 'P' || stc->map->map[i][j] == 'X')
	{
		if (stc->map->map[i][j] == 'X')
			mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->portal_ch,
				coordinate[0], coordinate[1]);
		else
			mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->ch, 
				coordinate[0], coordinate[1]);
		stc->ch->i = i;
		stc->ch->j = j;
		stc->ch->x = coordinate[0];
		stc->ch->y = coordinate[1];
	}
}

void	map_refresh(t_struct_control *stc)
{
	mlx_do_sync(stc->mlx);
	mlx_clear_window(stc->mlx, stc->win);
	put_image(stc);
}

#include "so_long.h"
int abc(struct_control *stc, int i, int j)
{
	if (stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] != '1')
	{
		stc->map->map[stc->map->enemy_i + i][stc->map->enemy_j + j] = 'M';
		stc->map->map[stc->map->enemy_i][stc->map->enemy_j] = '0';
		stc->map->enemy_i += i;
		stc->map->enemy_j += j;
		map_refresh(stc);
	}
	return (31);
}

void ghost_movement(struct_control *stc)
{
	int a = rand() % 4;
	if (a == 0) // ldaeft	
		abc(stc,0,-1);
	else if (a == 1) // right
		abc(stc,0,1);
	else if (a == 2) // down
		abc(stc,-1,0);
	else	// up
		abc(stc,1,0);
}
void mucox18_step_count(struct_control *stc, int i)
{
	static int step_count = 1;
	char *s = ft_itoa(step_count);
	mlx_string_put(stc->mlx, stc->win, 8,15 , 255, "Step Count: ");
	mlx_string_put(stc->mlx, stc->win, 10,30 , 255, s);
	if (i == 1)
		step_count++;
	free(s);
}
int all(struct_control *stc, int i, int j, char *path)
{
	static int step_count = 1;
	int pixel_x; 
	int pixel_y;

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
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == '0' || stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'C')
	{
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		stc->map_img->ch = mlx_xpm_file_to_image(stc->mlx, path, &pixel_x, &pixel_y);
		map_refresh(stc);
		mucox18_step_count(stc,1);
	}
	return (0);
}

void key_left(struct_control *stc)
{
	all(stc, 0, -1, "textures/chL.xpm");
}

void key_right(struct_control *stc)
{
	all(stc, 0, 1, "textures/chR.xpm");
}

void key_up(struct_control *stc)
{
	all(stc, -1, 0, "textures/chT.xpm");
}
void key_down(struct_control *stc)
{
	all(stc, 1, 0, "textures/chB.xpm");
}


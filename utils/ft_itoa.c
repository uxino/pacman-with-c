/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: museker <museker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:47:45 by museker           #+#    #+#             */
/*   Updated: 2023/09/03 16:45:57 by museker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	get_digits(int n)
{
	size_t	i;

	i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	if (!(str_num))
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}

int	portal_and_check_img(t_struct_control *stc, int i, int j)
{
	if (stc->map->map[stc->ch->i][stc->ch->j] == 'X' 
		&& stc->map->map[stc->ch->i + i][stc->ch->j + j] != '1')
	{
		stc->map->map[stc->ch->i][stc->ch->j] = 'E';
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		map_refresh(stc);
		mucox18_step_count(stc, 1);
		return (31);
	}
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'E')
	{
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'X';
		map_refresh(stc);
		if (stc->ch->is_finish == 1)
		{
			ft_printf("Game Over!");
			exit(0);
		}
		mucox18_step_count(stc, 1);
		return (31);
	}
	return (0);
}

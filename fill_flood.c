/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flood.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:42 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:45:50 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fill_f_check(t_so_long *so_long)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < so_long->map_y)
	{
		x = 0;
		while (x < so_long->map_x - 1)
		{
			if (ft_strchr("PEC", so_long->map_cpy[y][x]))
				ft_error(so_long);
			x++;
		}
		y++;
	}
}

void	ft_fill_f(char **map_cpy, t_point map, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= map.y || x >= map.x)
		return ;
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'F')
		return ;
	map_cpy[y][x] = 'F';
	ft_fill_f(map_cpy, map, y - 1, x);
	ft_fill_f(map_cpy, map, y + 1, x);
	ft_fill_f(map_cpy, map, y, x - 1);
	ft_fill_f(map_cpy, map, y, x + 1);
}

void	ft_fill_flood_3(char **map_copy, t_point map, t_point player)
{
	ft_fill_f(map_copy, map, player.y, player.x);
}

void	ft_fill_flood_2(t_so_long *so_long)
{
	t_point	map;
	t_point	player;

	map.x = so_long->map_x;
	map.y = so_long->map_y;
	player.x = so_long->p_x;
	player.y = so_long->p_y;
	ft_fill_flood_3(so_long->map_cpy, map, player);
	ft_fill_f_check(so_long);
}

void	fill_flood(t_so_long *so_long, char *str)
{
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	so_long->map_cpy = malloc(sizeof(char *) * (so_long->map_y + 1));
	i = 0;
	while (i < so_long->map_y)
	{
		so_long->map_cpy[i] = get_next_line(fd);
		i++;
	}
	so_long->map_cpy[i] = NULL;
	ft_fill_flood_2(so_long);
}

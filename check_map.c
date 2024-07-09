/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:53 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:46:42 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map3(t_so_long *so_long)
{
	if (so_long->p_count != 1 || so_long->e_count != 1
		|| so_long->c_count < 1)
		ft_print_error(so_long);
	if (so_long->map_x >= 41 || so_long->map_y >= 22)
		ft_print_error(so_long);
}

void	check_map2(t_so_long *so_long, int y, int x)
{
	y = 0;
	while (y < so_long->map_y)
	{
		x = 0;
		while (x < so_long->map_x)
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->p_count += 1;
				so_long->p_x = x;
				so_long->p_y = y;
			}
			if (so_long->map[y][x] == 'E')
			{
				so_long->e_count += 1;
				so_long->e_x = x;
				so_long->e_y = y;
			}
			if (so_long->map[y][x] == 'C')
				so_long->c_count += 1;
			x++;
		}
		y++;
	}
	check_map3(so_long);
}

void	check_new_line(t_so_long *so_long)
{
	int	y;

	y = -1;
	while (++y < so_long->map_y)
	{
		if (y == so_long->map_y - 1
			&& so_long->map[y][so_long->map_x - 1] != '\0')
			ft_print_error(so_long);
		else if (y < so_long->map_y - 1
			&& (so_long->map[y][so_long->map_x - 1] != '\n'
			|| so_long->map[y][so_long->map_x] != '\0'))
			ft_print_error(so_long);
	}
	check_map2(so_long, 0, 0);
}

void	check_map(t_so_long *so_long)
{
	int	y;
	int	x;

	y = -1;
	while (++y < so_long->map_y)
	{
		x = -1;
		while (++x < so_long->map_x - 1)
		{
			if ((y == 0 || y == so_long->map_y - 1)
				|| (x == 0 || x == so_long->map_x - 2))
			{
				if (so_long->map[y][x] != '1')
					ft_print_error(so_long);
			}
			if (!ft_strchr("10PEC", so_long->map[y][x]))
				ft_print_error(so_long);
		}
	}
	check_new_line(so_long);
}

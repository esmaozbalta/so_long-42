/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:49 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:46:29 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map3(t_so_long *so_long, int x, int y)
{
	if (so_long->map[y][x] == 'C')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->ground, x * 64, y * 64);
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->coin, x * 64, y * 64);
	}
	else if (so_long->map[y][x] == 'E')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->ground, x * 64, y * 64);
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->exit, x * 64, y * 64);
	}
}

void	create_map2(t_so_long *so_long, int x, int y)
{
	if (so_long->map[so_long->e_y][so_long->e_x] == '0')
		so_long->map[so_long->e_y][so_long->e_x] = 'E';
	if (so_long->map[y][x] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->ground, x * 64, y * 64);
	else if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->wall, x * 64, y * 64);
	else if (so_long->map[y][x] == 'P')
	{
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->ground, x * 64, y * 64);
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
			so_long->image->player, x * 64, y * 64);
	}
	else if (so_long->map[y][x] == 'C')
	{
		create_map3(so_long, x, y);
	}
	else if (so_long->map[y][x] == 'E')
	{
		create_map3(so_long, x, y);
	}
}

void	create_map(t_so_long *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (y < so_long->map_y)
	{
		x = -1;
		while (++x <= so_long->map_x)
		{
			if (so_long->map[y][x] == '0')
				create_map2(so_long, x, y);
			if (so_long->map[y][x] == '1')
				create_map2(so_long, x, y);
			if (so_long->map[y][x] == 'P')
				create_map2(so_long, x, y);
			if (so_long->map[y][x] == 'C')
				create_map2(so_long, x, y);
			if (so_long->map[y][x] == 'E')
				create_map2(so_long, x, y);
		}
		y++;
	}
}

void	image_map(t_so_long *so_long)
{
	int	x;
	int	y;

	so_long->image = malloc(sizeof(t_asset));
	so_long->image->player = mlx_xpm_file_to_image(so_long->mlx,
			"textures/dog.xpm", &x, &y);
	so_long->image->coin = mlx_xpm_file_to_image(so_long->mlx,
			"textures/bone.xpm", &x, &y);
	so_long->image->ground = mlx_xpm_file_to_image(so_long->mlx,
			"textures/ground.xpm", &x, &y);
	so_long->image->wall = mlx_xpm_file_to_image(so_long->mlx,
			"textures/wall.xpm", &x, &y);
	so_long->image->exit = mlx_xpm_file_to_image(so_long->mlx,
			"textures/exit.xpm", &x, &y);
	if (!so_long->image->player || !so_long->image->coin ||!so_long->image->exit
		|| !so_long->image->ground || !so_long->image->wall)
		ft_error(so_long);
}

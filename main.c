/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:16 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:55:47 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_zero(t_so_long	*so_long)
{
	so_long->c_number = 0;
	so_long->p_x = 0;
	so_long->p_y = 0;
	so_long->map_x = 0;
	so_long->map_y = 0;
	so_long->c_count = 0;
	so_long->p_count = 0;
	so_long->e_count = 0;
	so_long->move_count = 0;
	so_long->e_x = 0;
	so_long->e_y = 0;
}

int	main(int ac, char **av)
{
	t_so_long	so_long;

	if (ac != 2)
		return (0);
	check_map_ber(av[1]);
	check_map_name(av[1]);
	so_long.mlx = mlx_init();
	all_zero(&so_long);
	read_map(&so_long, av[1]);
	check_map(&so_long);
	fill_flood(&so_long, av[1]);
	so_long.mlx_win = mlx_new_window(so_long.mlx,
			(so_long.map_x - 1) * 64, so_long.map_y * 64, "SO_LONG");
	image_map(&so_long);
	create_map(&so_long);
	mlx_hook(so_long.mlx_win, 2, 0, moves, &so_long);
	mlx_hook(so_long.mlx_win, 17, 0, close_game, &so_long);
	mlx_loop(so_long.mlx);
	return (0);
}

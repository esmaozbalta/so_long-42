/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:43:01 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:49:05 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_asset
{
	void	*ground;
	void	*wall;
	void	*exit;
	void	*coin;
	void	*player;
}	t_asset;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_so_long
{
	void	*mlx;
	void	*mlx_win;

	char	**map_cpy;
	char	**map;
	int		map_x;
	int		map_y;

	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;	

	int		c_count;
	int		e_count;
	int		p_count;

	int		c_number;

	int		move_count;
	t_asset	*image;
}			t_so_long;

void	check_map_ber(char	*str);
void	check_map_name(char	*str);

void	check_map(t_so_long *so_long);

void	image_map(t_so_long *so_long);
void	create_map(t_so_long *so_long);

void	ft_print_error(t_so_long	*so_long);
void	ft_error(t_so_long	*so_long);

void	fill_flood(t_so_long *so_long, char *str);

int		close_game(t_so_long	*so_long);
void	win_game(t_so_long	*so_long);

int		moves(int keycode, t_so_long *move);

void	read_map(t_so_long *so_long, char *str);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:33 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:43:54 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keycode_2(t_so_long *move, int x, int y)
{
	move->move_count += 1;
	ft_printf("Move Count : %d\n", move->move_count);
	if (move->map[y][x + 1] == '0' || move->map[y][x + 1] == 'C')
	{
		if (move->map[y][x + 1] == 'C')
			move->c_number++;
		move->map[y][x] = '0';
		move->map[y][x + 1] = 'P';
		move->p_x++;
	}
	if (move->map[y][x + 1] == 'E')
	{
		if (move->c_count == move->c_number)
			win_game(move);
		else
		{
			move->map[y][x] = '0';
			move->map[y][x + 1] = 'P';
			move->p_x++;
		}
	}
}

void	keycode_0(t_so_long *move, int x, int y)
{
	move->move_count += 1;
	ft_printf("Move Count : %d\n", move->move_count);
	if (move->map[y][x - 1] == '0' || move->map[y][x - 1] == 'C')
	{
		if (move->map[y][x - 1] == 'C')
			move->c_number++;
		move->map[y][x] = '0';
		move->map[y][x - 1] = 'P';
		move->p_x--;
	}
	if (move->map[y][x - 1] == 'E')
	{
		if (move->c_count == move->c_number)
			win_game(move);
		else
		{
			move->map[y][x] = '0';
			move->map[y][x - 1] = 'P';
			move->p_x--;
		}
	}
}

void	keycode_13(t_so_long *move, int x, int y)
{
	move->move_count += 1;
	ft_printf("Move Count : %d\n", move->move_count);
	if (move->map[y - 1][x] == '0' || move->map[y - 1][x] == 'C')
	{
		if (move->map[y - 1][x] == 'C')
			move->c_number++;
		move->map[y][x] = '0';
		move->map[y - 1][x] = 'P';
		move->p_y--;
	}
	if (move->map[y - 1][x] == 'E')
	{
		if (move->c_count == move->c_number)
			win_game(move);
		else
		{
			move->map[y][x] = '0';
			move->map[y - 1][x] = 'P';
			move->p_y--;
		}
	}
}

void	keycode_1(t_so_long *move, int x, int y)
{
	move->move_count += 1;
	ft_printf("Move Count : %d\n", move->move_count);
	if (move->map[y + 1][x] == '0' || move->map[y + 1][x] == 'C')
	{
		if (move->map[y + 1][x] == 'C')
			move->c_number++;
		move->map[y][x] = '0';
		move->map[y + 1][x] = 'P';
		move->p_y++;
	}
	if (move->map[y + 1][x] == 'E')
	{
		if (move->c_count == move->c_number)
			win_game(move);
		else
		{
			move->map[y][x] = '0';
			move->map[y + 1][x] = 'P';
			move->p_y++;
		}
	}
}

int	moves(int keycode, t_so_long *move)
{
	int	x;
	int	y;

	x = move->p_x;
	y = move->p_y;
	if (keycode == 53)
		close_game(move);
	if (keycode == 2 && move->map[y][x + 1] != '1')
		keycode_2(move, x, y);
	if (keycode == 0 && move->map[y][x - 1] != '1')
		keycode_0(move, x, y);
	if (keycode == 13 && move->map[y - 1][x] != '1')
		keycode_13(move, x, y);
	if (keycode == 1 && move->map[y + 1][x] != '1')
		keycode_1(move, x, y);
	create_map(move);
	return (0);
}

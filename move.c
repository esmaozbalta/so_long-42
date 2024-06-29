#include "so_long.h"

int	moves(int	key, t_so_long	*move)
{
	int	x;
	int	y;

	x = move->p_x;
	y = move->p_y;
	if (key == 53)
		close_game(move);
	if (key == 2 && move->map[y][x + 1] != '1')
		key2(move, x, y);
	if (key == 0 && move->map[y][x - 1] != '1')
		key2(move, x, y);
	if (key == 13 && move->map[y - 1][x] != '1')
		key2(move, x, y);
	if (key == 1 && move->map[y + 1][x] != '1')
		key1(move, x, y);
	draw_map(move);
	return (0);
}

void	key2(t_so_long	*move, int	x, int	y)
{
	move->move_count += 1;
	ft_printf("Move Counter: %d\n", move->move_count);
	if (move->map[y][x + 1] == '0' || move->map[y][x + 1] == 'C')
	{
		if (move->map[y][x + 1] == 'C')
			move->c_count++;
		move->map[y][x] = '0';
		move->map[y][x + 1] = 'P';
		move->p_x++;
	}
	if (move->map[y][x + 1] == 'E')
	{
		if (move->c_count == move->c_number)
		{
			game_win(move);
		}
		else
		{
			move->map[y][x] = '0';
			move->map[y][x - 1] = 'P';
			move->p_x--;
		}
	}
}

void	key0(t_so_long	*move, int	x, int	y)
{
	move->move_count += 1;
	ft_printf("Move Counter: %d\n", move->move_count);
	if (move->map[y][x - 1] == '0' || move->map[y][x - 1] == 'C')
	{
		if (move->map[y][x - 1] == 'C')
			move->c_count++;
		move->map[y][x] = '0';
		move->map[y][x - 1] = 'P';
		move->p_x--;
	}
	if (move->map[y][x - 1] == 'E')
	{
		if (move->c_count == move->c_number)
		{
			game_win(move);
		}
		else
		{
			move->map[y][x] = '0';
			move->map[y][x - 1] = 'P';
			move->p_x--;
		}
	}
}

void	key13(t_so_long	*move, int	x, int	y)
{
	move->move_count += 1;
	ft_printf("Move Counter: %d\n", move->move_count);
	if (move->map[y - 1][x] == '0' || move->map[y - 1][x] == 'C')
	{
		if (move->map[y - 1][x] == 'C')
			move->c_count++;
		move->map[y][x] = '0';
		move->map[y - 1][x] = 'P';
		move->p_y--;
	}
	if (move->map[y - 1][x] == 'E')
	{
		if (move->c_count == move->c_number)
		{
			game_win(move);
		}
		else
		{
			move->map[y][x] = '0';
			move->map[y - 1][x] = 'P';
			move->p_y--;
		}
	}
}

void	key1(t_so_long	*move, int	x, int	y)
{
	move->move_count += 1;
	ft_printf("Move Counter: %d\n", move->move_count);
	if (move->map[y + 1][x] == '0' || move->map[y + 1][x] == 'C')
	{
		if (move->map[y + 1][x] == 'C')
			move->c_count++;
		move->map[y][x] = '0';
		move->map[y + 1][x] = 'P';
		move->p_y++;
	}
	if (move->map[y + 1][x] == 'E')
	{
		if (move->c_count == move->c_number)
		{
			game_win(move);
		}
		else
		{
			move->map[y][x] = '0';
			move->map[y + 1][x] = 'P';
			move->p_y++;
		}
	}
}

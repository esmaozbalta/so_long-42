#include "so_long.h"

void	ft_print_error(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("Map Error");
	while (so_long->map[i])
	{
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	exit (1);
}

void	error_free(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("Map Error!");
	while (so_long->copy_map[i])
	{
		if (so_long->copy_map != NULL)
		{
			free(so_long->copy_map[i]);
			free(so_long->map[i]);
		}
		i++;
	}
	free(so_long->copy_map);
	free(so_long->map);
	free(so_long);
	exit(1);
}

void	game_win(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("Congratulations!");
	while (so_long->map[i])
	{
		if (so_long->map[i] != NULL)
			free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	free(so_long);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	exit(1);
}

int	close_game(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("Game Closed");
	while (so_long->map[i])
	{
		if (so_long->map[i] != NULL)
			free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	free(so_long);
	mlx_destroy_window(so_long->mlx, so_long->mlx_win);
	exit(1);
}

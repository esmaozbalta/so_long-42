#include "so_long.h"

void	all_zero(t_so_long	*so_long)
{
	so_long->c_count = 0;

	so_long->c_count = 0;
	so_long->p_x = 0;
	so_long->p_y = 0;
	so_long->map_x = 0;
	so_long->map_y = 0;
	so_long->p_count = 0;
	so_long->e_count = 0;
	so_long->move_count = 0;
	so_long->e_x = 0;
	so_long->e_y = 0;

}

int	main(int	ac, char	**av)
{
	t_so_long	*so_long;

	if (ac != 2)
		return (0);
	so_long = malloc(sizeof(t_so_long));
	if (!so_long)
		return (0);
	all_zero(so_long);
	check_texture_files(so_long);
	check_map_ber(av[1]);
	check_map_name(av[1]);
	read_map(av[1], so_long);
	check_map(so_long);
	check_object(so_long);
	player_location(so_long);
	explore_map(so_long);
	so_long->mlx = mlx_init();
	image_map(so_long);
	draw_map(so_long);
	mlx_key_hook(so_long->mlx_win, moves, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, close_game, so_long);
	mlx_loop(so_long->mlx);
}

#include "so_long.h"

int	check_map(t_so_long	*checkmap)
{
	char	**map;
	int		x;
	int		y;

	y = -1;
	map = checkmap->map;
	if (!checkmap->map[0]) //harita bos ise error
		ft_print_error(checkmap);
	while (map[++y]) //her satir icin
	{
		x = -1;
		while (map[y][++x]) //her sutun icin
		{
			if ((y == 0 || y == checkmap->map_y - 1) && map[y][x] != '1') //haritanin sinirinda 1 disinda karakter var ise error
				ft_print_error(checkmap);
			else if ((x == 0 || x == checkmap->map_x - 1) && map[y][x] != '1') //haritanin sinirinda 1 disinda karakter var ise error
				ft_print_error(checkmap);
			else if (!ft_strchr("10ECP", checkmap->map[y][x])) //bu karakter disinda karakter var ise error
				ft_print_error(checkmap);
		}
		if (checkmap->map_x != x) //satir uzunlugu beklenen boyutta degilse
			ft_print_error(checkmap);
	}
	return (1);
}

void	player_location(t_so_long	*so_long)
{
	int	x;
	int	y;

	y = -1;
	while(so_long->map[++y])
	{
		x = -1;
		while(so_long->map[y][++x])
		{
			if (so_long->map[y][x] == 'P')
			{
				so_long->p_x = x; //playerin x konumunu atar
				so_long->p_y = y;
			}
			else if (so_long->map[y][x] == 'E')
			{
				so_long->e_x = x; // exitim x konumunu atar
				so_long->e_y = y;
			}
		}
	}
}

void	image_map(t_so_long	*map)
{
	int	x;
	int	y;

	map->coin = mlx_xpm_file_to_image(map->mlx, "coin.xpm", &x, &y); //-
	map->player = mlx_xpm_file_to_image(map->mlx, "dog_player.xpm", &x, &y);
	map->wall = mlx_xpm_file_to_image(map->mlx, "wall1.xpm", &x, &y);
	map->ground = mlx_xpm_file_to_image(map->mlx, "wall2.xpm", &x, &y);
	map->exit = mlx_xpm_file_to_image(map->mlx, "home.xpm", &x, &y); //-
	if (!map->player || !map->exit || !map->coin || !map->wall || !map->ground)
		ft_print_error(map);
	map->mlx_win = mlx_new_window(map->mlx, map->map_x * 64, map->map_y * 64, "SOLONG");
}

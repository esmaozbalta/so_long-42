#include "so_long.h"

void	draw_map(t_so_long	*so_long)
{
	int	x;
	int	y;

	if (so_long->map[so_long->e_y][so_long->e_x] == '0') //exit konumunda 0 var ise E yapar
		so_long->map[so_long->e_y][so_long->e_x] = 'E';
	y = -1;
	while (so_long->map[++y]) //haritayi dolasmaya baslar
	{
		x = -1;
		while (so_long->map[y][++x]) //her hucre icin fonksiyonu cagirir
		{
			if (so_long->map[y][x] == '0')
				put_image_map(so_long, x, y);
			else if (so_long->map[y][x] == '1')
				put_image_map(so_long, x, y);
			else if (so_long->map[y][x] == 'P')
				put_image_map(so_long, x, y);
			else if (so_long->map[y][x] == 'C')
				put_image_map(so_long, x, y);
			else if (so_long->map[y][x] == 'E')
				put_image_map(so_long, x, y);
		}
	}
}

void	put_image_map(t_so_long	*so_long, int	x, int	y)
{
	if (so_long->map[y][x] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->ground, x * 64, y * 64);
	else if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->wall, x * 64, y * 64);
	else if (so_long->map[y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->player, x * 64, y * 64);
	else if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->coin, x * 64, y * 64);
	else if (so_long->map[y][x] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->mlx_win, so_long->exit, x * 64, y * 64);
}

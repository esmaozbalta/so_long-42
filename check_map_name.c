#include "so_long.h"

void	check_map_ber(char	*str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i <= 3)
	{
		ft_printf("MAP NAME WRONG");
		exit (1);
	}
	if (str[i] != 'r' || str[i - 1] != 'e'
			|| str[i - 2] != 'b' || str[i - 3] != '.')
	{
		ft_printf("MAP NAME WRONG");
		exit (1);
	}
	if (str[i - 4] == '.' || str[i - 4] == '/')
	{
		if (str[i - 5] && str[i - 4] != '/')
			return ;
		ft_printf("MAP NAME WRONG");
		exit (1);
	}
}

void	check_map_name(char	*str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("MAP NOT FOUND");
		exit (1);
	}
}

//flood_fill

void	explore(t_so_long	*so_long, int	y, int	x)
{
	char	**map;

	map = so_long->copy_map;
	if (y < 0 || x < 0 || x >= so_long->map_x || so_long->map_y)
		return ; //sinirlarin disina cikarsa fonksiyondan cik
	if (map[y][x] == 'X' || map[y][x] == '1') //daha once ziyaret edildiyse veya duvar ise
		return ;
	map[y][x] = 'X'; //ziyaret edildi olarak isaretle
	explore(so_long, y - 1, x); //yukari hucreye bak
	explore(so_long, y + 1, x); //alt hucreye bak
	explore(so_long, y, x - 1); //sol hucreye bak
	explore(so_long, y, x + 1); //sag hucreye bak
}

void	explore_map(t_so_long	*so_long)
{
	int	x;
	int	y;

	explore(so_long, so_long->p_y, so_long->p_x); //baslangic noktasidan baslatir
	y = -1;
	while (so_long->copy_map[++y]) //tum haritayi dolasir
	{
		x = -1;
		while (so_long->copy_map[y][++x])
		{
			if (ft_strchr("EC", so_long->copy_map[y][x])) //Xler dolduruldugu halde E veya C kalmisa hata verir
				error_free(so_long);
		}
	}
	x = -1;
	while (so_long->copy_map[++x])
	{
		free(so_long->copy_map[x]);
	}
	free(so_long->copy_map);
}

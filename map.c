#include "so_long.h"

int	maplen(t_so_long	*so_long, char	*map)
{
	int		len;
	int		fd;
	char	*read_map;

	len = 0;
	fd = open(map, O_RDONLY);
	read_map = get_next_line(fd); //ilk satiri okur
	so_long->map_x = ft_strlen(read_map); // ilk satirin (sutun) uzunligini x e atar
	while (read_map) //dosyanin sonu gelene kadar don
	{
		len++; //satir sayisi artar
		free(read_map);
		read_map = get_next_line(fd); //bir sonraki satiri okur
	}
	so_long->map_y = len; //satir sayisini y ye atar
	close(fd);
	return (len); //satir sayisini doner
}

void	copy_map(char	*map, t_so_long	*so_long)
{
	int	i;
	int	len;
	int	fd;

	i = 0;
	len = maplen(so_long, map); //satir sayisini atar
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	so_long->copy_map = malloc(sizeof(char *) * (len + 1));
	if (!so_long->copy_map)
		return ;
	while (i < len) //satir satir okur ve copy_map e atar
	{
		so_long->copy_map[i] = get_next_line(fd);
		i++;
	}
	so_long->copy_map[i] = NULL;
	close(fd);
}

void	read_map(char	*map, t_so_long	*so_long)
{
	int	i;
	int	len;
	int	fd;

	i = 0;
	len = maplen(so_long, map); //satir sayisi gelir
	fd = open(map, O_RDONLY);
	if (fd < 0) //dosya acilmazsa fonksiyondan cikar
		return ;
	so_long->map = malloc(sizeof(char *) * (len + 1));
	if (!so_long->map)
		return ;
	while (i < len) //harita dosyasini satir satir okur
	{
		so_long->map[i] = get_next_line(fd);
		i++;
	}
	so_long->map[i] = NULL;
	close(fd);
	copy_map(map, so_long);
	if (so_long->map_x >= 40 || so_long->map_y >= 22)
		ft_print_error(so_long);
}

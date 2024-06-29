#include "so_long.h"

void	error_texture(t_so_long	*so_long)
{
	int	i;

	ft_printf("Texture Error!");
	i = 0;
	free(so_long);
	exit(1);
}

void	check_texture_files(t_so_long	*so_long)
{
	int	fd;

	fd = open("dog_player.xpm", O_RDONLY);
	if (fd == -1)
		error_texture(so_long);
	fd = open("wall2.xpm", O_RDONLY);
	if (fd == -1)
		error_texture(so_long);
}

void	count_object(t_so_long	*so_long) //nesneleri sayar
{
	int	x;
	int	y;

	so_long->c_count = 0;
	so_long->p_count = 0;
	so_long->e_count = 0;
	y = -1;
	while (so_long->map[++y])
	{
		x = -1;
		while (so_long->map[y][++x])
		{
			if (so_long->map[y][x] == 'P')
				so_long->p_count += 1;
			else if (so_long->map[y][x] == 'C')
				so_long->c_count += 1;
			else if (so_long->map[y][x] == 'E')
				so_long->e_count += 1;
		}
	}
}

void	check_object(t_so_long	*so_long)
{
	count_object(so_long);

	if (so_long->p_count != 1) //player sayisi 1 degilse error
		ft_print_error(so_long);
	else if (so_long->e_count != 1) // cikis sayisi 1 degilse
		ft_print_error(so_long);
	else if (so_long->c_count < 1) // coin sayisi 1 den kucuk ise
		ft_print_error(so_long);
}

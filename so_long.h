#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "getnextline/get_next_line.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_so_long
{
	void	*mlx;
	void	*mlx_win;
	void	*coin;
	void	*player;
	void	*exit;
	void	*ground;
	void	*wall;

	char	**copy_map;
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

}			t_so_long;

void	check_map_ber(char	*str);
void	check_map_name(char	*str);
void	explore(t_so_long	*so_long, int	y, int	x);
void	explore_map(t_so_long	*so_long);

void	error_texture(t_so_long	*so_long);
void	check_texture_files(t_so_long	*so_long);
void	count_object(t_so_long	*so_long);
void	check_object(t_so_long	*so_long);

void	ft_print_error(t_so_long	*so_long);
void	error_free(t_so_long	*so_long);
void	game_win(t_so_long	*so_long);
int		close_game(t_so_long	*so_long);

int		maplen(t_so_long	*so_long, char	*map);
void	copy_map(char	*map, t_so_long	*so_long);
void	read_map(char	*map, t_so_long	*so_long);

int		check_map(t_so_long	*checkmap);
void	player_location(t_so_long	*so_long);
void	image_map(t_so_long	*map);

void	draw_map(t_so_long	*so_long);
void	put_image_map(t_so_long	*so_long, int	x, int	y);

int		moves(int	key, t_so_long	*move);
void	key2(t_so_long	*move, int	x, int	y);
void	key0(t_so_long	*move, int	x, int	y);
void	key13(t_so_long	*move, int	x, int	y);
void	key1(t_so_long	*move, int	x, int	y);

#endif
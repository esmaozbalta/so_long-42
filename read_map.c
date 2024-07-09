/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:28 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:58:26 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_counter(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

void	read_map(t_so_long *so_long, char *str)
{
	int	fd;
	int	i;

	fd = open(str, O_RDONLY);
	i = 0;
	so_long->map_y = ft_line_counter(fd);
	so_long->map = malloc(sizeof(char *) * (so_long->map_y + 1));
	if (!so_long->map)
		return ;
	close(fd);
	open(str, O_RDONLY);
	while (i < so_long->map_y)
	{
		so_long->map[i] = get_next_line(fd);
		i++;
	}
	so_long->map[i] = NULL;
	so_long->map_x = ft_strlen(so_long->map[0]);
	close(fd);
}

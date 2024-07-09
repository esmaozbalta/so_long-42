/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:38 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:42:41 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("Game Closed\n");
	while (so_long->map[i])
	{
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	exit(1);
}

void	win_game(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("You Win! Congratulations!\n");
	while (so_long->map[i])
	{
		if (so_long->map[i] != NULL)
			free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	exit(1);
}

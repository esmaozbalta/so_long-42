/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:47 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:45:59 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("Map Error!");
	while (so_long->map[i])
	{
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	exit (1);
}

void	ft_error(t_so_long	*so_long)
{
	int	i;

	i = 0;
	ft_printf("Map Error!");
	while (so_long->map_cpy[i])
	{
		if (so_long->map_cpy[i] != NULL)
		{
			free(so_long->map_cpy[i]);
			free(so_long->map[i]);
		}
		i++;
	}
	free(so_long->map_cpy);
	free(so_long->map);
	exit(1);
}

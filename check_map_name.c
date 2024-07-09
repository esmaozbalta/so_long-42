/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:42:56 by esozbalt          #+#    #+#             */
/*   Updated: 2024/07/09 16:47:19 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

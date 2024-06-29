/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:30:12 by esozbalt          #+#    #+#             */
/*   Updated: 2023/12/17 16:30:33 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		len2;
	char	*dst;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(len + len2 + 1);
	if (!dst)
	{
		return (NULL);
	}
	ft_strlcpy(dst, s1, len + 1);
	ft_strlcat(dst, s2, (len + len2 + 1));
	return (dst);
}

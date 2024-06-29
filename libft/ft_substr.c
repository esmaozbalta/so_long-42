/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:53:49 by esozbalt          #+#    #+#             */
/*   Updated: 2023/12/17 14:53:52 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;

	slen = ft_strlen(s);
	if (slen < start)
	{
		return (ft_strdup(""));
	}
	slen = ft_strlen(s + start);
	if (slen < len)
	{
		len = slen;
	}
	substr = (char *)malloc(len + 1);
	if (!substr)
	{
		return (NULL);
	}
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

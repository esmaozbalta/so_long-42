/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:40:38 by esozbalt          #+#    #+#             */
/*   Updated: 2024/02/08 16:40:41 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_hex(unsigned long a, char *s)
{
	int	len;

	len = 0;
	if (a >= 16)
		len += ft_hex(a / 16, s);
	len += ft_putchar(s[a % 16]);
	return (len);
}

int	ft_putnbr(long n)
{
	long	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		len++;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	else
	{
		len += ft_putchar(48 + n);
	}
	return (len);
}

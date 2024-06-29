/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:53:04 by esozbalt          #+#    #+#             */
/*   Updated: 2024/02/08 14:53:06 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list arg, char f)
{
	int	len;

	len = 0;
	if (f == 'c')
		len += ft_putchar(va_arg(arg, int));
	else if (f == 's')
		len += ft_putstr(va_arg(arg, char *));
	else if (f == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_hex(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	else if (f == 'd' || f == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (f == 'u')
		len += ft_putnbr(va_arg(arg, unsigned int));
	else if (f == 'x')
		len += ft_hex(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (f == 'X')
		len += ft_hex(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (f == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		len;

	va_start(arg, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			len += ft_format(arg, *(++str));
		}
		else
		{
			len += ft_putchar(*str);
		}
		str++;
	}
	va_end(arg);
	return (len);
}

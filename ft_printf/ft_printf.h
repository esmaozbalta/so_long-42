/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esozbalt <esozbalt@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:52:58 by esozbalt          #+#    #+#             */
/*   Updated: 2024/02/08 14:53:01 by esozbalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);

int	ft_format(va_list args, char f);

int	ft_putchar(char c);

int	ft_putstr(char *s);

int	ft_hex(unsigned long a, char *s);

int	ft_putnbr(long n);

#endif

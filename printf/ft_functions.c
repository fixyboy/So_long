/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <fhassane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:49:53 by fhassane          #+#    #+#             */
/*   Updated: 2024/12/14 14:37:32 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int n)
{
	int		i;
	char	*hex_base;

	i = 0;
	hex_base = "0123456789abcdef";
	if ((long)n < 0)
		n = (unsigned long)((long)n);
	if (n == 0)
	{
		i += ft_putchar('0');
		return (i);
	}
	if (n >= 16)
		i = i + ft_putnbr_hex(n / 16);
	i = i + ft_putchar(hex_base[n % 16]);
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_int(int c)
{
	int	count;

	count = 0;
	if (c == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (c < 0)
	{
		c *= -1;
		write(1, "-", 1);
		count++;
	}
	if (c > 9)
	{
		count += ft_print_int(c / 10);
		ft_print_int(c % 10);
	}
	else
		ft_putchar(c + '0');
	return (count + 1);
}

/*static int	calculate_hex_length(unsigned long n)
{
	int	length;

	length = 0;
	while (n > 0)
	{
		n /= 16;
		length++;
	}
	if (length == 0)
		return (1);
	else
		return (length);
}
*/
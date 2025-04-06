/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <fhassane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 20:24:00 by fhassane          #+#    #+#             */
/*   Updated: 2024/12/14 14:46:33 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_ptr(uintptr_t nb)
{
	if (nb >= 16)
		ft_put_ptr(nb / 16);
	if (nb % 16 < 10)
		ft_putchar((nb % 16) + '0');
	else
		ft_putchar((nb % 16) + 87);
}

int	ft_putptr(uintptr_t ptr)
{
	int	len;

	if (ptr == 0)
	{
		(write(1, "(nil)", 5));
		return (5);
	}
	write(1, "0x", 2);
	ft_put_ptr(ptr);
	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr /= 16;
	}
	return (len + 2);
}

static int	ft_print_unsigned(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_print_unsigned(nb / 10);
	i += ft_putchar((nb % 10) + '0');
	return (i);
}

int	ft_put_unsigned_z(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += ft_putchar('0');
	else
		count += ft_print_unsigned(nb);
	return (count);
}

int	ft_putnbr_hex_cap(unsigned int n)
{
	int		i;
	char	*hex_base;

	i = 0;
	hex_base = "0123456789ABCDEF";
	if (n >= 16)
		i = i + ft_putnbr_hex_cap(n / 16);
	i = i + ft_putchar(hex_base[n % 16]);
	return (i);
}

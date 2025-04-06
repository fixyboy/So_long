/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhassane <fhassane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:52:43 by fhassane          #+#    #+#             */
/*   Updated: 2024/12/18 18:44:10 by fhassane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checksym(va_list args, const char sym)
{
	int	i;

	i = 0;
	if (sym == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (sym == 'd' || sym == 'i')
		i = ft_print_int(va_arg(args, int));
	else if (sym == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (sym == 'p')
		i = ft_putptr(va_arg(args, uintptr_t));
	else if (sym == 'u')
		i = ft_put_unsigned_z(va_arg(args, unsigned int));
	else if (sym == '%')
		i = ft_putchar('%');
	else if (sym == 'x')
		i = ft_putnbr_hex(va_arg(args, unsigned int));
	else if (sym == 'X')
		i = ft_putnbr_hex_cap(va_arg(args, unsigned int));
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		return_value;
	va_list	args;
	int		i;

	i = 0;
	return_value = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			return_value = return_value + ft_checksym(args, format[i + 1]);
			i++;
		}
		else
			return_value = return_value + ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (return_value);
}
/*int main(void)
{
    int int_max = 2147483647;
    int int_min = -2147483648;
    unsigned int uint_max = 4294967295;
    unsigned long ulong_max = 18446744073709551615UL;
    long long ll_max = 9223372036854775807LL;
    long long ll_min = -9223372036854775807LL;
    char *str = "Hello 42";
    void *ptr = (void *)0x12345678;

    printf("Standard printf:\n");
    printf("Test 1: %d\n", int_max);
    printf("Test 2: %d\n", int_min);
    printf("Test 3: %i\n", int_max);
    printf("Test 4: %i\n", int_min);
    printf("Test 5: %s\n", str);
    printf("Test 6: %u\n", uint_max);
    printf("Test 7: %x\n", uint_max);
    printf("Test 8: %X\n", uint_max);
    printf("Test 9: %p\n", ptr);

    printf("\nft_printf output:\n");
    ft_printf("Test 1: %d\n", int_max);
    ft_printf("Test 2: %d\n", int_min);
    ft_printf("Test 3: %i\n", int_max);
    ft_printf("Test 4: %i\n", int_min);
    ft_printf("Test 5: %s\n", str);
    ft_printf("Test 6: %u\n", uint_max);
    ft_printf("Test 7: %x\n", uint_max);
    ft_printf("Test 8: %X\n", uint_max);
    ft_printf("Test 9: %p\n", ptr);

    return 0;
}*/
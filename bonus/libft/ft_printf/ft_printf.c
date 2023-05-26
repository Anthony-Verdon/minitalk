/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:54:34 by averdon           #+#    #+#             */
/*   Updated: 2022/10/26 21:17:04 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	replace(int c, va_list args)
{
	int		num_char;
	char	*hexa;

	num_char = 0;
	hexa = "0123456789abcdef";
	if (c == 'c')
		num_char = ft_putchar(va_arg(args, int));
	else if (c == 's')
		num_char = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_check_pointer(va_arg(args, unsigned long), hexa, &num_char);
	else if (c == 'd' || c == 'i')
		ft_putnbr_dec(va_arg(args, int), &num_char);
	else if (c == 'u')
		ft_put_unbr(va_arg(args, unsigned int), "0123456789", &num_char);
	else if (c == 'x')
		ft_putnbr_hex(va_arg(args, int), hexa, &num_char);
	else if (c == 'X')
		ft_putnbr_hex(va_arg(args, int), "0123456789ABCDEF", &num_char);
	else if (c == '%')
		num_char = ft_putchar('%');
	return (num_char);
}

static int	check(char c, va_list args)
{
	int	len_write;

	len_write = 0;
	if (ft_strchr("cspdiuxX%", c))
		len_write += replace(c, args);
	else
	{
		len_write += ft_putchar('%');
		len_write += ft_putchar(c);
	}
	return (len_write);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		len_write;

	if (!str)
		return (-1);
	va_start(args, str);
	len = ft_strlen(str);
	i = 0;
	len_write = 0;
	while (i < len)
	{
		if (str[i] == '%')
		{
			i++;
			len_write += check(str[i], args);
		}
		else
			len_write += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len_write);
}

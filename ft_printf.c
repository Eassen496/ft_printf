/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:35:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 14:30:25 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "./header/ft_printf.h"

static int	ft_printf_handler(char c, va_list arg)
{
	int	len;

	len = -1;
	if (c == 'c')
		len = ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		len = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (c == 'p')
		len = ft_putptr_fd(va_arg(arg, unsigned long long), 1); 
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (c == 'u')
		len = ft_putunbr_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'x')
		len = ft_putnbr_hex_fd(va_arg(arg, unsigned int), 1);
	else if (c == 'X')
		len = ft_putnbr_hex_fd(va_arg(arg, unsigned int), 1);
	else if (c == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *main, ...)
{
	int		i;
	va_list	arg;
	int		ret;

	ret = 0;
	i = 0;
	va_start(arg, main);
	while (main[i])
	{
		if (main[i] == '%')
			ret += ft_printf_handler(main[++i], arg);
		else
			ret += write(1, &main[i], 1);
		i++;
	}
	va_end(arg);
	return (ret);
}

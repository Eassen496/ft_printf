/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:40:23 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 15:06:57 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <stdio.h>

static int	ft_putnbr_write(int n, int intlen, int start, char *num)
{
	while (intlen > start)
	{
		num[--intlen] = (n % 10) + '0';
		n = n / 10;
	}
	return (write(1, num, ft_strlen(num)));
}

static int	ft_putnbr_intlen(long long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_putnbr_fd(int n)
{
	char	*num;
	int		intlen;
	int		start;
	int		ret;

	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	intlen = ft_putnbr_intlen(n);
	start = 0;
	num = malloc((intlen + 1) * sizeof(char));
	if (!num)
		return (-1);
	num[intlen] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		n = -n;
		start++;
	}
	ret = ft_putnbr_write(n, intlen, start, num);
	free(num);
	return (ret);
}

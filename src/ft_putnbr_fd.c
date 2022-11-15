/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:40:23 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 00:43:49 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	int_to_char(int n, int fd)
{
	char	c;

	if (n < 10 && n >= 0)
	{
		c = 48 + n;
	}
	return (write(fd, &c, 1));
}

static int	printverif(int nb, int supposedlen)
{
	int	ret;

	ret = 0;
	while (nb > 0)
	{
		nb /= 10;
		ret++;
	}
	if (ret == supposedlen)
		return (supposedlen);
	else
		return (-1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	isprint;
	int	save;

	isprint = 0;
	save = n;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
	{
		isprint += write(fd, "-", 1);
		n = -n;
	}
	if (n < 10 && n > -1)
		isprint += int_to_char(n, fd);
	else
	{
		while (n > 0)
		{
			i = n % 10;
			n = n / 10;
			isprint += int_to_char(i, fd);
		}
	}
	return (printverif(save, isprint));
}

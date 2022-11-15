/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:19:00 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 00:44:45 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	putnbr_hex_fd_len(int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static int	ft_putnbr_hex_fd(int nbr, char *base, int fd)
{
	int		j;
	char	*result;
	int		len;

	len = putnbr_hex_fd_len(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (-1);
	result[len] = '\0';
	while (nbr > 0)
	{
		j = nbr % 16;
		nbr = nbr % 16;
		result[len--] = base[j];
	}
	len = ft_strlen(result);
	j = write (fd, &result, len);
	free(result);
	return (j);
}

int	savespace(int nbr, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	return (ft_putnbr_hex_fd(nbr, base, fd));
}

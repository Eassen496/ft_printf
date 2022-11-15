/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:19:00 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 12:32:40 by ale-roux         ###   ########.fr       */
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

int	ft_putnbr_hex_fd(int nbr, int fd)
{
	int		j;
	char	*result;
	int		len;
	char	*base;

	len = putnbr_hex_fd_len(nbr);
	base = "0123456789abcdef";
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (-1);
	result[len] = '\0';
	while (len != 0)
	{
		j = nbr % 16;
		nbr = nbr / 16;
		result[--len] = base[j];
	}
	len = ft_strlen(result);
	j = write (fd, &result, len);
	free(result);
	return (j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:01:23 by ale-roux          #+#    #+#             */
/*   Updated: 2024/11/21 01:58:05 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../header/ft_printf.h"

static int	putptr_fd_len(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		i++;
		nbr = nbr / 16;
	}
	return (i + 2);
}

int	ft_putptr_fd(unsigned long long nbr, int fd)
{
	int		j;
	char	*result;
	int		len;
	char	*base;

	if (nbr == 0)
            return (write(fd, "(nil)", 5));
        len = putptr_fd_len(nbr);
	base = "0123456789abcdef";
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (-1);
	result[len] = '\0';
	while (len > 2)
	{
		j = nbr % 16;
		nbr = nbr / 16;
		result[--len] = base[j];
	}
	result[0] = '0';
	result[1] = 'x';
	len = ft_strlen(result);
	j = write(fd, result, len);
	free(result);
	return (j);
}

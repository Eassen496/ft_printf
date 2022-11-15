/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 21:26:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/11/15 17:20:31 by ale-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_hexup_fd(unsigned int nbr, int fd);
int		ft_putnbr_hexdown_fd(unsigned int nbr, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
size_t	ft_strlen(char *str);
int		ft_printf(const char *main, ...);
int		ft_putptr_fd(unsigned long long int nbr, int fd);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:21:04 by ale-roux          #+#    #+#              #
#    Updated: 2022/11/15 17:24:47 by ale-roux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./src/ft_putchar_fd.c ./src/ft_putnbr_fd.c ./src/ft_putnbr_hexup_fd.c \
		  ./src/ft_putstr_fd.c ./src/ft_putunbr_fd.c ./src/ft_strlen.c \
		  ft_printf.c ./src/ft_putptr_fd.c ./src/ft_putnbr_hexdown_fd.c
NAME	= libftprintf.a
OBJS	=  ${SRCS:.c=.o}

.c.o	:
		gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
		ar rc ${NAME} ${OBJS}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 08:06:16 by fideguch          #+#    #+#              #
#    Updated: 2020/08/03 08:10:27 by fideguch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
SRCS    = ft_calloc.c ft_itoa.c ft_puthex.c ft_strlen.c ft_atoi.c ft_infomalloc.c ft_putstr_fd.c ft_unsigned_itoa.c ft_bzero.c ft_isdigit.c ft_putchar_fd.c ft_strlcpy.c
OBJS    = $(SRCS:.c=.o)
INCS    = libft.h
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o

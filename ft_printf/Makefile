# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 08:16:12 by fideguch          #+#    #+#              #
#    Updated: 2020/08/07 00:39:34 by fideguch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SOURCE = ft_printf.c put_char.c put_string.c put_int.c put_ints_utils.c put_unsigned_int.c process.c put_pointer.c put_unsigned_int_hex.c put_per.c

LIB_PATH = ./libft

HED = ./include/ft_printf.h

SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/,$(SOURCE))

OBJ = $(SOURCE:.c=.o)

$(NAME):
	make re -C $(LIB_PATH)
	gcc $(FLAGS) -c $(SRC) -I $(HED)
	ar rcs $(NAME) $(OBJ) $(LIB_PATH)/*.o

all: $(NAME)

clean:
	make clean -C $(LIB_PATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re: fclean all

test:
	gcc main.c $(NAME)

.PHONY: all clean fclean re bonus test

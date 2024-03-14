# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:33:33 by corellan          #+#    #+#              #
#    Updated: 2024/03/14 14:24:05 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_utils.c

OUT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = ft_printf.h

CC = cc

all: $(NAME)

$(NAME): $(OUT)
		$(MAKE) -C ./libft
		cp libft/libft.a .
		mv libft.a libftprintf.a
		$(CC) -c $(FLAGS) -I$(LIB) $(SRC)
		ar rc $(NAME) $(OUT)
		ranlib $(NAME)

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OUT)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
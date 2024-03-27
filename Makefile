# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 13:33:33 by corellan          #+#    #+#              #
#    Updated: 2024/03/28 00:26:46 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_print.c 

SRC_B = ft_printf_bonus.c ft_printf_print_bonus.c ft_printf_utils_bonus.c \
ft_printf_flags_bonus.c ft_printf_flags_print_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIB = -I.

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) bonus -C ./libft
		cp libft/libft.a .
		mv libft.a libftprintf.a
		$(CC) -c $(FLAGS) $(LIB) $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

bonus: .bonus

.bonus: $(OBJ_B)
		$(MAKE) bonus -C ./libft
		cp libft/libft.a .
		mv libft.a libftprintf.a
		$(CC) -c $(FLAGS) $(LIB) $(SRC_B)
		ar rc $(NAME) $(OBJ_B)
		ranlib $(NAME)
		@touch .bonus

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJ) $(OBJ_B)
		@rm -f .bonus

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
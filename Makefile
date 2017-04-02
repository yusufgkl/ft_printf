# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygokol <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/02 15:36:48 by ygokol            #+#    #+#              #
#    Updated: 2017/04/02 16:42:52 by ygokol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = ./adress_wch.c\
	  ./colors.c\
	  ./create_type.c\
	  ./create_type_adds.c\
	  ./ft_atoi.c\
	  ./ft_bzero.c\
	  ./ft_charblank.c\
	  ./ft_isdigit.c\
	  ./ft_printf.c\
	  ./ft_putchar.c\
	  ./ft_putnbr.c\
	  ./ft_putstr.c\
	  ./ft_strchr.c\
	  ./ft_strcmp.c\
	  ./ft_strcpy.c\
	  ./ft_strdup.c\
	  ./ft_strjoin.c\
	  ./ft_strlen.c\
	  ./ft_strnew.c\
	  ./ft_strsub.c\
	  ./int_plus.c\
	  ./int_space.c\
	  ./itoa_base.c\
	  ./itoa_base_count.c\
	  ./print_int.c\
	  ./print_int_dot.c\
	  ./print_int_dot_small.c\
	  ./str_c.c\
	  ./w_chars.c\

INC = 		./header.h\
	  		./libft.h\

OBJ =		$(SRC:.c=.o)

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GRE) ===== Compilation en cours =====$(DEF)"
	@$(CC) $(FLAGS) -c $(SRC) -I $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GRE) ===== Compilation terminee  =====$(DEF)"

clean:
	@echo "$(GRE) ===== FCLEAN    en cours    =====$(DEF)"
	@rm -f $(OBJ)
	@echo "$(GRE) ===== FCLEAN    termine     =====$(DEF)"

fclean: clean
	@echo "$(GRE) ===== CLEAN    en cours     =====$(DEF)"
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@echo "$(GRE) ===== CLEAN    termine      =====$(DEF)"

re: fclean all

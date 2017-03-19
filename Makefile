# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumiguel <jumiguel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 16:20:10 by aaudiber          #+#    #+#              #
#    Updated: 2017/03/17 15:27:14 by ygokol           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./ft_printf.c\
	  ./flags.c\
	  ./utils.c\
	  ./parsing.c\
	  ./conv_di.c\
	  ./conv_ouxX.c\

OBJC = ./ft_printf.o\
	  ./flags.o\
	  ./utils.o\
	  ./parsing.o\
	  ./conv_di.o\
	  ./conv_ouxX.o\

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h\
	./libft.h\

FLAGS = -Wall -Wextra -Werror

LIBFT = libft/*.c

all: $(NAME)

$(NAME): $(OBJC)
	@gcc $(FLAGS) -c $(SRC) $(LIBFT) -I $(INC)
	@ar rc $(NAME) $(OBJC) ./libft/*.o
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJC)

fclean:
	@rm -rf $(NAME)
	@rm -rf $(OBJC)

re:
	@make fclean all

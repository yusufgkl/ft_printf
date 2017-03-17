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

NAME = ok

SRC = ./ft_printf.c\
	  ./flags.c\
	  ./utils.c\
	  ./parsing.c\

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	@/bin/echo "-----Compilating sources-----"
	@make -C ./libft
	@/bin/echo "---Done---"
	@/bin/echo "-----Creating executable-----"
	@gcc $(FLAGS) -o $(NAME) $(SRC) ./libft/libft.a
	@/bin/echo "---Done---"

clean:
	@/bin/echo "-----cleaning-----"
	@/bin/rm -f $(OBJ)
	@make clean -C ./libft

fclean:
	@/bin/echo "-----fcleaning-----"
	@/bin/rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

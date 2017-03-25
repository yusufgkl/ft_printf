NAME = libftprintf.a

SRC = ./ft_printf.c\
	  ./flags.c\
	  ./utils.c\
	  ./parsing.c\
	  ./conv_di.c\
	  ./conv_ouxX.c\
	  ./conv_p.c\
	  ./conv_C.c\
	  ./print.c\

OBJC = ./ft_printf.o\
	  ./flags.o\
	  ./utils.o\
	  ./parsing.o\
	  ./conv_di.o\
	  ./conv_ouxX.o\
	  ./conv_p.o\
	  ./conv_C.o\
	  ./print.o\

OBJ = $(SRC:.c:.o)

FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h\
	./libft.h\

FLAGS = -Wall -Wextra -Werror -Wpointer-to-int-cast

LIBFT = libft/*.c

all: $(NAME)

$(NAME): $(OBJC)
	@gcc $(FLAGS) -c $(SRC) $(LIBFT) -I $(INC)
	@ar rc $(NAME) $(OBJC) ./libft/*.o
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJC)
	@rm -rf ./*.o

fclean:
	@rm -rf $(NAME)
	@rm -rf $(OBJC)
	@rm -rf ./*.o

re:
	@make fclean all

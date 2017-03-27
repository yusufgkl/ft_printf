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

OBJ = $(SRC:.c=.o)

OBJDIR = obj

FLAGS = -Wall -Werror -Wextra

INC = ./ft_printf.h\
	./libft.h\

FLAGS = -Wall -Wextra -Werror -Wpointer-to-int-cast

LIBFT = libft/*.c

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
	@echo "$(GRE)===== Compilation en cours =====$(DEF)";
	@clang $(FLAGS) -c $(SRC) $(LIBFT) -I $(INC)
	@ar rc $(NAME) $(OBJ) ./libft/*.o
	@ranlib $(NAME)
	@echo "$(GRE)===== Compilation terminee =====$(DEF)";

clean:
	@echo "$(GRE)===== Nettoyage en cours   =====$(DEF)";
	@rm -rf $(OBJ)
	@rm -rf ./*.o
	@echo "$(GRE)===== Nettoyage termine    =====$(DEF)";

fclean:
	@echo "$(GRE)===== Nettoyage en cours   =====$(DEF)";
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@rm -rf ./*.o
	@echo "$(GRE)===== Nettoyage termine    =====$(DEF)";

re:
	@echo "$(GRE)=====          re          =====$(DEF)";
	@make fclean all

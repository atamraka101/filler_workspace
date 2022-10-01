NAME = a.out
SRC = ./*.c
OBJ = $(SRC:.c=.o)
HEADER = includes/... //
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror
LIB_A = libft/libft.a

all : $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -c $(SRC)
		gcc $(OBJ) $(LIB_A) $(FLAGS) -o $(NAME)

clean:
			rm -f $(OBJ)
			rm -f $(NAME)

fclean: clean
			rm -f $(NAME)
			make fclean -C libft/

re: fclean all

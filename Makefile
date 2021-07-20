NAME = push_swap
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC =   srcs/push_swap.c          \

INC =   inc/push_swap.h             \
        libft/libft.h               \

LIB = -L ./libft -lft

all: $(NAME)

$(NAME):
	gcc -g3 -fsanitize=address $(FLAGS) -o $(NAME) $(SRC) $(LIB)

skiperror:
	gcc -o $(NAME) $(SRC) -g $(LIB)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

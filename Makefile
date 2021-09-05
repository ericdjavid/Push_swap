NAME = push_swap
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC =   srcs/push_swap.c          \
        srcs/errors.c             \
        srcs/stack_moves.c        \
        srcs/utils.c              \
        srcs/sorter.c             \
        srcs/large_stack.c

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

.PHONY: all skiperror clean fclean re

NAME = push_swap
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC =   srcs/push_swap.c          \
        srcs/errors.c             \
        srcs/stack_moves.c        \
        srcs/utils.c              \
        srcs/sorter.c             \
        srcs/large_stack.c         \
        srcs/large_strat1.c         \
        srcs/large_strat2.c         \
        srcs/free.c                 \
        srcs/init.c                 \
        srcs/push_to_b_groups.c     \

INC =   inc/push_swap.h             \
        libft/libft.h               \

LIB = -L ./libft -lft

all: $(NAME)

$(NAME):
	gcc -g -fsanitize=address $(FLAGS) -o $(NAME) $(SRC) $(LIB)

skiperror:
	gcc -ggdb -o $(NAME) $(SRC) -g $(LIB)

clean:
	@rm -rf *.o
	@echo "cleaning .o files"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all skiperror clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = operations1.c operations2.c operations3.c pars_part1.c pars_part2.c utils_linked.c \
		ft_split.c sorting.c sort_helpers.c small_sort.c main.c

OBJ = $(SRC:%.c=%.o)
NAME = push_swap
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$@ $?

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) libftprintf.a

re: fclean $(NAME)

.PHONY: all clean fclean re

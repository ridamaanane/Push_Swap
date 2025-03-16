CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = operations1.c operations2.c operations3.c pars_part1.c pars_part2.c utils_linked.c \
		ft_split.c sorting.c sort_helpers.c small_sort.c main.c
SRCB = bonus/operations1_bonus.c bonus/operations2_bonus.c bonus/operations3_bonus.c \
		bonus/pars_part1_bonus.c bonus/pars_part2_bonus.c bonus/utils_linked_bonus.c \
		bonus/ft_split_bonus.c bonus/small_sort_bonus.c \
		bonus/main_bonus.c bonus/checker_bonus.c \
		bonus/get_next_line.c bonus/get_next_line_utils.c

OBJ = $(SRC:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)
NAME = push_swap
CHECKER = checker
RM = rm -f

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(CHECKER): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(CHECKER)  

clean:
	@$(RM) $(OBJ) $(OBJB)

fclean: clean
	@$(RM) $(NAME) $(CHECKER)

re: fclean all

.SECONDARY: $(OBJ) $(OBJB)
.PHONY: all clean fclean re bonus

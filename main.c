#include "push_swap.h"

int	main(int ac, char **av)
{
	int i;
	int *arr;

	list_t *stack_a;
	list_t *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = ac - 1;
	stack_a = pars_args(&av[1], i);
	if (!stack_a)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	arr = make_arr(stack_a);
	if (!check_duplicate(arr, list_len(stack_a)))
	{
		write (2, "Error\n", 6);
		free(arr);
		free_stack(stack_a);
		return (0);
	}
	if (stack_already_sorted(stack_a))
	{
		free_stack(stack_a);
		return (1);
	}
	sort_stack_by_size(&stack_a, &stack_b, arr);
	//print_list(stack_a);
	free_stack(stack_a);
}


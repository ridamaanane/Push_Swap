#include "push_swap.h"

int pars_arr(char **arr, list_t **stack)
{
	int i;
	long n;

	if (!arr || !*arr) // !*arr mean first element = 0
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!check_valid_input(arr[i]))
			return (0);
		n = ft_atol(arr[i]);
		if(n > INT_MAX || n < INT_MIN)
			return (0);
		add_node_end(stack, (int)n);
		i++;
		
	}
	return (1);
}
int pars_str(char *input, list_t **stack)
{
	char **arr;

	arr = ft_split(input , ' ');
	if (!arr || !*arr)
	{
		free_arr(arr); //free the strings inside arr
		return (0);
	}
	if (!pars_arr(arr, stack))
	{
		free(arr); //only free the array itself
		return (0);
	}
	free_arr(arr);
	return (1);
}
list_t *pars_args(char **arg, int size)
{
	int i;
	list_t *stack;

	// size mean The number of elements in arg

	stack = NULL;
	i = 0;
	while (i < size)
	{
		if (!pars_str(arg[i], &stack))
		{
			free_stack(stack); //Free the entire stack if parts_Str return (0)
			return (NULL);
		}
		i++;
	}
	return (stack);
}

int check_duplicate(int *tab, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] == tab[i + 1])
			return (0); 
		i++;
	}
	return (1);
}

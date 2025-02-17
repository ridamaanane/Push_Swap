#include "push_swap.h"

int calc_operations(list_t **b, int max)
{
	int size_b;

	size_b = list_len(*b);
	if (max > size_b / 2)
		return (max - size_b);
	else
		return (max);
}
int *make_arr(list_t *stack)
{
	int *arr;
	int size;
	int i;

	size = list_len(stack);
	arr = malloc(sizeof(int) * (size));
	if (!arr)
		return (NULL);
	i = 0;
	while (stack && i < size)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	sort_array(arr, size);
	return (arr);
}
void sort_array(int *array, int size)
{
	int i;
	int j;
	int swap;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
			}
			j++;
		}
		i++;
	}
}
int stack_already_sorted(list_t *stack_a)
{
	list_t *temp;

	temp = stack_a;
	if (!stack_a)
		return(0);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void sort_stack_by_size(list_t **a, list_t **b, int *arr)
{
	if (list_len(*a) > 10)
		sort_stack(a, b, arr, list_len(*a));
	else if (list_len(*a) <= 10)
		small_sort(a, b);
	free(arr);
}

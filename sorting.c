#include "push_swap.h"

void push_to_stack_b(list_t **a, list_t **b, int min, int max)
{
	int size_b;

	if (!*a)
		return ;
	while (1)
	{
		size_b = list_len(*b);
		if ((*a)->value <= min)
		{
			pb(a, b);
			rb(b);
			return ;
		}
		else if ((*a)->value <= max)
		{
			pb(a, b);
			if (size_b > 1 && (*b)->value < (*b)->next->value)
				sb(b);
			return ;
		}
		else
			ra(a);
	}
}
int big_index(list_t **b)
{
	int i;
	int big_index;
	int max;
	list_t *temp;

	i = 0;
	temp = *b;
	max = temp->value;
	big_index = 0;
	while (temp)
	{
		if (temp->value > max)
		{
			max = temp->value;
			big_index = i;
		}
		i++;
		temp = temp->next;
	}
	return (big_index);
}

void push_to_stack_a(list_t **a, list_t **b, int max)
{
	int operations;

	operations = calc_operations(b , max);
	while (operations > 0)
	{
		operations--;
		rb(b);
	}
	while (operations < 0)
	{
		operations++;
		rrb(b);
	}
	pa(a, b);
}
void loop_in_stack_b(list_t **b, list_t **a)
{
	while (list_len(*b) > 0)
		push_to_stack_a(a, b, big_index(b));
}
void sort_stack(list_t **stack_a, list_t **stack_b, int *arr, int size)
{
	int max;
	int i;
	int size_a;

	if (size > 100)
		max = size / 13;
	else
		max = size / 6;
	
	i = 0;
	size_a = list_len(*stack_a);
	while (list_len(*stack_a) > 0)
	{
		push_to_stack_b(stack_a, stack_b, arr[i], arr[max]);
		if (i < max)
			i++;
		if (max < size_a - 1)
			max++;
	}
	loop_in_stack_b(stack_b, stack_a);
}

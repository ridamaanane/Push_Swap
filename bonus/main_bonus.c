/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:01:33 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 22:32:32 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int check_duplicate_2(t_list *stack_a)
{
	t_list *current;
	t_list *walk;

	current = stack_a;
	while (current)
	{
		walk = current->next;
		while (walk)
		{
			if (current->value == walk->value)
				return (1);
			walk = walk->next;
		}
		current = current->next;
	}
	return (0);
}
int	stack_already_sorted(t_list *stack_a)
{
	t_list	*temp;

	temp = stack_a;
	if (!stack_a)
		return (0);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
void print_s(t_list *h)
{
	while (h)
	{
		printf("%d ", h->value);
		h = h->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_a = pars_args(&av[1], ac - 1);
	stack_b = NULL;
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (check_duplicate_2(stack_a))
	{
		write(2, "Error\n", 6);
		free_stack(stack_a);
		return (0);
	}
	read_from_stack(&stack_a, &stack_b);
	check_bonus(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
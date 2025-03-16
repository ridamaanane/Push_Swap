/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:01:33 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/16 13:51:16 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int i;
	int *arr;

	t_list *stack_a;
	t_list *stack_b;

	if (ac < 2)
		return (0);

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
		free(arr);
		return (0);
	}
	sort_stack_by_size(&stack_a, &stack_b, arr);
	//print_list(stack_a);
	free_stack(stack_a);
}

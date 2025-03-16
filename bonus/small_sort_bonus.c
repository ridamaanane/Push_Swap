/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:02:25 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/16 00:29:12 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	pos_of_min(t_list **a)
{
	int		i;
	int		min_index;
	t_list	*temp;
	int		min;

	i = 0;
	min_index = 0;
	temp = *a;
	min = temp->value;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	return (min_index);
}

void	sort_3(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;
	int	size;

	size = list_len(*stack_a);
	if (size != 3)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first > third)
		ra(stack_a);
	if (second > first && second > third)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	small_sort(t_list **a, t_list **b)
{
	int	min_pos;

	if (list_len(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
		return ;
	}
	while (list_len(*a) > 3)
	{
		min_pos = pos_of_min(a);
		if (min_pos <= list_len(*a) / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
			while (min_pos++ < list_len(*a))
				rra(a);
		pb(a, b);
	}
	sort_3(a);
	while (list_len(*b) > 0)
		pa(a, b);
}

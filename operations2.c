/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:01:52 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 03:09:50 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*before_last;
	t_list	*last;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next->next != NULL)
		temp = temp->next;
	before_last = temp;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*before_last;
	t_list	*last;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next->next != NULL)
		temp = temp->next;
	before_last = temp;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:01:45 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 23:25:10 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
}

void	ra(t_list **stack_a)
{
	t_list	*temp;
	t_list	*end;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	end = *stack_a;
	while (end->next != NULL)
	{
		end = end->next;
	}
	end->next = temp;
	temp->next = NULL;
}

void	rb(t_list **stack_b)
{
	t_list	*temp;
	t_list	*end;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	end = *stack_b;
	while (end->next != NULL)
	{
		end = end->next;
	}
	end->next = temp;
	temp->next = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:01:45 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/09 03:21:25 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
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
	write(1, "pb\n", 3);
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

// int main() {
//     t_list *stack_a = malloc(sizeof(t_list));
//     t_list *n1 = malloc(sizeof(t_list));
//     t_list *n2 = malloc(sizeof(t_list));

//     stack_a->value = 3;
//     stack_a->next = n1;

//     n1->value = 2;
//     n1->next = n2;

//     n2->value = 1;
//     n2->next = NULL;

//     printf("Before rra():\n");
//     t_list *temp = stack_a;
//     while (temp) {
//         printf("stack_a: %d\n", temp->value);
//         temp = temp->next;
//     }

//     sb(&stack_a);

//     printf("\nAfter rra():\n");

//     temp = stack_a;
//     while (temp) {
//         printf("%d\n", temp->value);
//         temp = temp->next;
//     }
//     return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:06:00 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 18:06:03 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

t_list	*add_node_end(t_list **head, int value)
{
	t_list	*last_node;
	t_list	*temp;

	last_node = malloc(sizeof(t_list));
	if (!last_node)
		return (NULL);
	last_node->value = value;
	last_node->next = NULL;
	temp = *head;
	if (!*head)
		*head = last_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = last_node;
	}
	return (last_node);
}

void	print_list(t_list *h)
{
	while (h)
	{
		printf("%d\n", h->value);
		h = h->next;
	}
}

int	list_len(t_list *h)
{
	int	i;

	i = 0;
	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

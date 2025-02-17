#include "push_swap.h"

void free_stack(list_t *stack)
{
    list_t *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

list_t *add_node_end(list_t **head, int value)
{
	list_t *last_node = malloc(sizeof(list_t));
	if (!last_node)
		return (NULL);
	list_t *temp;
	
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
void print_list(list_t *h)
{
    while (h)
    {
        printf("%d\n", h->value);
        h = h->next;
    }
}
int	list_len(list_t *h)
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
// int main() 
// {
// 	list_t *stack1 = NULL;

//     add_node_end(&stack1, 16);
// 	add_node_end(&stack1, 11);
//     add_node_end(&stack1, 13);

// 	print_list(stack1);

//     free_stack(stack1);

// 	// printf("%d\n", (stack1)->value);

//     return 0;
// }

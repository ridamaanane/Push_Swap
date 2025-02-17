#include "push_swap.h"

void rr(list_t **stack_a, list_t **stack_b)
{
    ra(stack_a);
    rb(stack_b);

    write(1, "rr\n", 3);
}

void rra(list_t **stack_a)
{
    if (!*stack_a || (*stack_a)->next == NULL)
		return ;

    list_t *temp;
    list_t *before_last;
    list_t *last;

    
    temp = *stack_a;
    while (temp->next->next != NULL)
        temp = temp->next;

    before_last = temp;
    last = before_last->next;
    before_last->next = NULL;

    last->next = *stack_a;
    *stack_a = last;

    write(1, "rra\n", 3);
}
void rrb(list_t **stack_b)
{
    if (!*stack_b || (*stack_b)->next == NULL)
        return;

    list_t *temp;
    list_t *before_last;
    list_t *last;

    temp = *stack_b;
    while(temp->next->next != NULL)
        temp = temp->next;

    before_last = temp;
    last = before_last->next;
    before_last->next = NULL;

    last->next = *stack_b;
    *stack_b = last;

    write(1, "rrb\n", 3);
}
void rrr(list_t **stack_a, list_t **stack_b)
{
    rra(stack_a);
    rrb(stack_b);

    write(1, "rrr\n", 3);
}

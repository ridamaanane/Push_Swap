#include "push_swap.h"

void sa(list_t **stack_a)
{
    if (!*stack_a || (*stack_a)->next == NULL)
        return;
    list_t *first;
    list_t *second;

    first = *stack_a;
    second = (*stack_a)->next;

    first->next = second->next;
    second->next = first;

    *stack_a = second;

    write(1, "sa\n", 3);
}

void sb(list_t **stack_b)
{
    if (!*stack_b || (*stack_b)->next == NULL)
        return;

    list_t *first;
    list_t *second;

    first = *stack_b;
    second = (*stack_b)->next;

    first->next = second->next;
    second->next = first;

    *stack_b = second;

    write(1, "sb\n", 3);
}
void ss(list_t **stack_a, list_t **stack_b)
{
    sa(stack_a);
    sb(stack_b);

    write(1, "ss\n", 3);
}

#include "push_swap.h"

void pa(list_t **stack_a, list_t **stack_b)
{
	if (!*stack_b)
        return;

    list_t *temp;

    temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;

    write(1, "pa\n", 3);
}
void pb(list_t **stack_a, list_t **stack_b)
{
	if (!*stack_a)
		return ;

	list_t *temp;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp; //updates stack_b to make temp the new head. ..
    //(katgol lih dir liya *stack_b ypointe 3la ayy haja kaypointe 3liha temp)

    write(1, "pb\n", 3);
}
void ra(list_t **stack_a)
{
    if (!*stack_a || (*stack_a)->next == NULL)
		return ;

    list_t *temp;
    list_t *end;

    temp = *stack_a;
    *stack_a = (*stack_a)->next;

    end = *stack_a;
    while(end->next != NULL)
    {
        end = end->next;
    }
    end->next = temp;
    temp->next = NULL;

    write(1, "ra\n", 3);
}
void rb(list_t **stack_b)
{
    if (!*stack_b || (*stack_b)->next == NULL)
		return ;

    list_t *temp;
    list_t *end;

    temp = *stack_b;
    *stack_b = (*stack_b)->next;

    end = *stack_b;
    while(end->next != NULL)
    {
        end = end->next;
    }
    end->next = temp;
    temp->next = NULL;

    write(1, "rb\n", 3);
}




// int main() {
//     list_t *stack_a = malloc(sizeof(list_t));
//     list_t *n1 = malloc(sizeof(list_t));
//     list_t *n2 = malloc(sizeof(list_t));

//     stack_a->value = 3;
//     stack_a->next = n1;

//     n1->value = 2;
//     n1->next = n2;

//     n2->value = 1;
//     n2->next = NULL;

//     printf("Before rra():\n");
//     list_t *temp = stack_a;
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
//     return 0;
// }

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct list_s {
    int value;
    struct list_s *next;
} list_t;

//operations
void pa(list_t **stack_b, list_t **stack_a);
void pb(list_t **stack_a, list_t **stack_b);
void ra(list_t **stack_a);
void rb(list_t **stack_b);
void rr(list_t **stack_a, list_t **stack_b);
void rra(list_t **stack_a);
void rrb(list_t **stack_b);
void rrr(list_t **stack_a, list_t **stack_b);
void sa(list_t **stack_a);
void sb(list_t **stack_b);
void ss(list_t **stack_a, list_t **stack_b);

//utils linked lists
void free_stack(list_t *stack);
list_t *add_node_end(list_t **head, int value);
void print_list(list_t *h);
int	list_len(list_t *h);

//parsing
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
long	ft_atol(const char *str);
void free_arr(char **arr);
int check_valid_input(char *input);
char	**ft_split(const char *s, char c);
int pars_arr(char **arr, list_t **stack);
int pars_str(char *input, list_t **stack);
list_t *pars_args(char **arg, int size);
int check_duplicate(int *tab, int len);

//sorting
void push_to_stack_b(list_t **a, list_t **b, int min, int max);
int big_index(list_t **b);
void push_to_stack_a(list_t **a, list_t **b, int max);
void loop_in_stack_b(list_t **b, list_t **a);
void sort_stack(list_t **stack_a, list_t **stack_b, int *arr, int size);

//sorting_helpers
int calc_operations(list_t **b, int max);
int *make_arr(list_t *stack);
void sort_array(int *array, int size);
int stack_already_sorted(list_t *stack_a);
void sort_stack_by_size(list_t **a, list_t **b, int *arr);


//small_sort
int pos_of_min(list_t **a);
void sort_3(list_t **stack_a);
void small_sort(list_t **stack_a, list_t **stack_b);


#endif 

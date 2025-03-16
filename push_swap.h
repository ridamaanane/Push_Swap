/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:02:15 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/16 00:48:03 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct list_s
{
	int				value;
	struct list_s	*next;
}					t_list;

// operations
void				pa(t_list **stack_b, t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);

// utils linked lists
void				free_stack(t_list *stack);
t_list				*add_node_end(t_list **head, int value);
void				print_list(t_list *h);
int					list_len(t_list *h);

// parsing
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
long				ft_atol(const char *str);
void				free_arr(char **arr);
int					check_valid_input(char *input);
char				**ft_split(const char *s, char c);
int					pars_arr(char **arr, t_list **stack);
int					pars_str(char *input, t_list **stack);
t_list				*pars_args(char **arg, int size);
int					check_duplicate(int *tab, int len);

// sorting
void				push_to_stack_b(t_list **a, t_list **b, int min, int max);
int					big_index(t_list **b);
void				push_to_stack_a(t_list **a, t_list **b, int max);
void				loop_in_stack_b(t_list **b, t_list **a);

// sorting_helpers
int					calc_operations(t_list **b, int max);
int					*make_arr(t_list *stack);
void				sort_array(int *array, int size);
int					stack_already_sorted(t_list *stack_a);
void				sort_stack_by_size(t_list **a, t_list **b, int *arr);
void	sort_stack(t_list **stack_a, t_list **stack_b, int *arr, int size);

// small_sort
int					pos_of_min(t_list **a);
void				sort_3(t_list **stack_a);
void				small_sort(t_list **stack_a, t_list **stack_b);

#endif

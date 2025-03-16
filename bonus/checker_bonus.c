/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 18:05:07 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/16 16:09:14 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int read_from_stack(t_list **stack_a, t_list **stack_b)
{
    char *line;

    line = get_next_line(0);
    while (line)
    {
        if (!check_and_execute(line, stack_a, stack_b))
        {
            free(line);
            write (2, "Error\n", 6);
            get_next_line(-1);
            free_stack(*stack_a);
            free_stack(*stack_b);
            exit(1);
        }
        free(line);
        line = get_next_line(0);
    }
    return (0);
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]); 
}

int check_and_execute(char *input, t_list **stack_a, t_list **stack_b)
{
    if (ft_strcmp(input, "sa\n") == 0)
        sa(stack_a);
    else if (ft_strcmp(input, "sb\n") == 0)
        sb(stack_b);
    else if (ft_strcmp(input, "ss\n") == 0)
        ss(stack_a, stack_b);
    else if (ft_strcmp(input, "pa\n") == 0)
        pa(stack_a, stack_b);
    else if (ft_strcmp(input, "pb\n") == 0)
        pb(stack_a, stack_b);
    else if (ft_strcmp(input, "ra\n") == 0)
        ra(stack_a);
    else if (ft_strcmp(input, "rb\n") == 0)
        rb(stack_b);
    else if (ft_strcmp(input, "rr\n") == 0)
        rr(stack_a, stack_b);
    else if (ft_strcmp(input, "rra\n") == 0)
        rra(stack_a);
    else if (ft_strcmp(input, "rrb\n") == 0)
        rrb(stack_b);
    else if (ft_strcmp(input, "rrr\n") == 0)
        rrr(stack_a, stack_b);
    else
        return (0);
    return (1);
}
void check_bonus(t_list *stack_a, t_list *stack_b)
{
    if (stack_already_sorted(stack_a) && stack_b == NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}
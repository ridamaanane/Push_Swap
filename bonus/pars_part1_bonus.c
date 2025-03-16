/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_part1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:02:04 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 18:06:41 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	pars_arr(char **arr, t_list **stack)
{
	int		i;
	long	n;

	if (!arr || !*arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		if (!check_valid_input(arr[i]))
			return (0);
		n = ft_atol(arr[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		add_node_end(stack, (int)n);
		i++;
	}
	return (1);
}

int	pars_str(char *input, t_list **stack)
{
	char	**arr;

	arr = ft_split(input, ' ');
	if (!arr || !*arr)
	{
		free_arr(arr);
		return (0);
	}
	if (!pars_arr(arr, stack))
	{
		free_arr(arr);
		return (0);
	}
	free_arr(arr);
	return (1);
}

t_list	*pars_args(char **arg, int size)
{
	int		i;
	t_list	*stack;

	stack = NULL;
	i = 0;
	while (i < size)
	{
		if (!pars_str(arg[i], &stack))
		{
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}

int	check_duplicate(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] == tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

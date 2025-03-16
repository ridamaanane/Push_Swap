/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaanane <rmaanane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:01:24 by rmaanane          #+#    #+#             */
/*   Updated: 2025/03/15 23:38:59 by rmaanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_countwords(const char *str, char c)
{
	int	i;
	int	word;
	int	count;

	i = 0;
	word = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			if (word == 0)
			{
				word++;
				count++;
			}
		}
		else
			word = 0;
		i++;
	}
	return (count);
}

int	ft_wordlen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_wordcpy(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free(char **str, int i)
{
	while (i > 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	int (i), (size), (len_word);
	if (!s)
		return (NULL);
	size = ft_countwords(s, c);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		len_word = ft_wordlen(s, c);
		result[i] = malloc(sizeof(char) * (len_word + 1));
		if (!result[i])
			return (ft_free(result, i), NULL);
		ft_wordcpy(result[i++], s, len_word);
		s += len_word;
	}
	result[i] = NULL;
	return (result);
}

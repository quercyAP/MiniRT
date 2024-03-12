/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 09:33:27 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_ws(int c)
{
	if (c == '\t' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static int	count_words(const char *str)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (!check_ws(*str) && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (check_ws(*str))
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**splitter(char const *s)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s) + 1) * sizeof(char *));
	if (!s || !(split))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= (size_t)ft_strlen(s))
	{
		if (!check_ws(s[i]) && index < 0)
			index = i;
		else if ((check_ws(s[i]) || i == (size_t)ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

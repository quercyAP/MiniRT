/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 16:03:11 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static int	check_ws(int c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v' || c == ' ')
	{
		return (1);
	}
	return (0);
}

static int	check(int *i, char *str)
{
	int	sign;

	sign = 1;
	while (str[*i])
	{
		if (check_ws(str[*i]))
			(*i)++;
		else
			break ;
	}
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
		if (str[*i] == '+' || str[*i] == '-')
			return (0);
	}
	if (str[*i] == '+')
	{
		(*i)++;
		if (str[*i] == '+' || str[*i] == '-')
			return (0);
	}
	return (sign);
}

double	ft_atod(char *str)
{
	double	ret;
	int		i;
	double	sign;
	double	j;

	i = 0;
	sign = check(&i, (char *)str);
	if (sign == 0)
		return (0);
	ret = 0;
	while (str[i] && ft_isdigit(str[i]))
		ret = (ret * 10) + (str[i++] - 48);
	if (str[i] == '.')
	{
		i++;
		j = 1.0;
		while (str[i] && ft_isdigit(str[i]))
		{
			ret = ret + ((double)(str[i] - 48.0) / pow(10, j));
			i++;
			j += 1.0;
		}
	}
	return (ret * sign);
}

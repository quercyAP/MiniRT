/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 21:12:13 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_pf(char *s, int *count)
{
	unsigned int	i;

	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		(*count) += 6;
		return (0);
	}
	i = 0;
	while (s[i])
	{
		if (write(1, (s + i), 1) == -1)
			return (-1);
		i++;
		(*count)++;
	}
	return (0);
}

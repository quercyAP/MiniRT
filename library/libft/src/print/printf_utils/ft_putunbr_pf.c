/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 21:12:24 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr_pf(unsigned int n, int *count)
{
	if (n >= 10)
	{
		if (ft_putunbr_pf(n / 10, count))
			return (-1);
		if (ft_putunbr_pf(n % 10, count))
			return (-1);
	}
	else
		if (ft_putchar_pf((n + 48), count) == -1)
			return (-1);
	return (0);
}

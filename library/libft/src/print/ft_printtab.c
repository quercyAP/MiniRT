/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:31:51 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/19 13:12:01 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtab(char *label, char **char_tab)
{
	int	i;

	if (label)
		ft_printf(FT_WHITE"%s "FT_CLEAR, label);
	if (!char_tab)
	{
		ft_printf(FT_RED"is NULL\n"FT_CLEAR);
		return ;
	}
	else if (label)
		ft_putstr_fd(":\n", 1);
	i = 0;
	while (char_tab[i])
	{
		ft_printf(FT_GREEN"[%s]"FT_CLEAR, char_tab[i]);
		i++;
	}
	if (char_tab[i] == NULL)
		ft_printf(FT_PURPLE"[null]\n"FT_CLEAR);
}

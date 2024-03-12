/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:03:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/19 14:26:24 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab_dup(char **str_tab)
{
	int		i;
	char	**tab_ret;

	i = 0;
	tab_ret = ft_new_strtab(ft_strtab_len(str_tab));
	if (!tab_ret)
		return (NULL);
	while (i < ft_strtab_len(str_tab))
	{
		tab_ret[i] = ft_strdup(str_tab[i]);
		if (!(tab_ret[i]))
		{
			ft_strtab_clear(tab_ret);
			return (NULL);
		}
		i++;
	}
	return (tab_ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:31:51 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/19 14:04:23 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlist_str(char *label, t_list *list)
{
	t_list	*local;

	local = list;
	if (label)
		ft_printf(FT_WHITE"%s "FT_CLEAR, label);
	if (!local)
	{
		ft_printf(FT_RED"is NULL\n"FT_CLEAR);
		return ;
	}
	else if (label)
		ft_putstr_fd(":\n", 1);
	while (local)
	{
		ft_printf(FT_GREEN"[%s]"FT_CLEAR, (char *)local->content);
		local = local->next;
	}
	ft_putstr_fd("\n", 1);
}

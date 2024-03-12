/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:54 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 21:09:02 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_rev(t_list *lst, void (*f)(void *))
{
	t_list	*local;

	local = ft_lstlast(lst);
	while (local && f)
	{
		(*f)(local->content);
		local = local->prev;
	}
}

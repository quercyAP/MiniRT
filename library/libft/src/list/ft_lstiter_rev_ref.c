/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_rev_ref.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:28:54 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/19 13:08:50 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_rev_ref(t_list *lst, void (*f)(void *, t_list *))
{
	t_list	*local;

	local = ft_lstlast(lst);
	while (local && f)
	{
		(*f)(local->content, local);
		local = local->prev;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_ref.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/04/12 09:39:37 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_ref(t_list *lst, void *param,
				int (*f)(void *, t_list *, void *))
{
	t_list	*local;

	local = lst;
	while (local && f)
	{
		if ((*f)(local->content, local, param))
			return (local);
		local = local->next;
	}
	return (NULL);
}

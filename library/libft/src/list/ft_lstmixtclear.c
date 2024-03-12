/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmixtclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 14:55:51 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmixtclear(t_list_mixt **lst, void (*del)(void*))
{
	t_list_mixt	*tmp;

	if (!lst || !del)
		return ;
	while ((*lst))
	{
		tmp = (*lst)->next;
		ft_lstmixtdelone((*lst), del);
		(*lst) = tmp;
	}
}

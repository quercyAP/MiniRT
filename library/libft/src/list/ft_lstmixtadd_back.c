/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmixtadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 14:50:08 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmixtadd_back(t_list_mixt **lst, t_list_mixt *new)
{
	t_list_mixt	*tmp;

	tmp = (*lst);
	if (!lst)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
	{
		tmp = ft_lstmixtlast(*(lst));
		tmp->next = new;
		new->prev = tmp;
	}
}

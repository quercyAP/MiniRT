/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 21:09:13 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*nlst_start;
	t_list	*nlst_node;
	void	*tmp_content;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	nlst_start = NULL;
	while (tmp)
	{
		tmp_content = f(tmp->content);
		nlst_node = ft_lstnew(tmp_content);
		if (!nlst_node)
		{
			del(tmp_content);
			ft_lstclear(&nlst_start, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst_start, nlst_node);
		tmp = tmp->next;
	}
	return (nlst_start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmixtnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 14:45:56 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_mixt	*ft_lstmixtnew(void *content, int type)
{
	t_list_mixt	*ret;

	ret = ft_calloc(1, sizeof(t_list_mixt));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->type = type;
	return (ret);
}

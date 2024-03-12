/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:58:56 by Tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 21:20:40 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!needle[0])
	{
		return ((char *)haystack);
	}
	i = 0;
	while (i < len && haystack[i])
	{
		if (!(ft_strncmp(&((char *)haystack)[i], needle, ft_strlen(needle)))
			&& (ft_strlen(needle) <= (len - i)))
		{
			return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}

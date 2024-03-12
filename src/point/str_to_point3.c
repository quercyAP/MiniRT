/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_point3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 09:42:00 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	str_to_point3(char *tab_cel)
{
	char		**tab;
	t_point3	ret;

	tab = ft_split(tab_cel, ',');
	ret = new_point3(ft_atod(tab[0]), ft_atod(tab[1]), ft_atod(tab[2]));
	ft_strtab_clear(tab);
	return (ret);
}

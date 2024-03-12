/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:00:07 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	str_to_color(char *tab_cel)
{
	char		**tab;
	t_color		ret;

	tab = ft_split(tab_cel, ',');
	ret = new_color((unsigned char)ft_atoi(tab[0]),
			(unsigned char)ft_atoi(tab[1]),
			(unsigned char)ft_atoi(tab[2]), 255);
	ft_strtab_clear(tab);
	return (ret);
}

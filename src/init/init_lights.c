/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:05:38 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	find_lights(void *content, void *data)
{
	char		**tab_param;
	t_light		*light;
	static int	id = 1;

	tab_param = ((t_pars_line *)content)->token_tab;
	if (!ft_strcmp(tab_param[0], "L"))
	{
		light = ft_calloc(sizeof(t_light), 1);
		*light = new_light(str_to_point3(tab_param[1]), ft_atod(tab_param[2]),
				str_to_color(tab_param[3]));
		light->id = id;
		ft_lstadd_back(&((t_data *)data)->lst_light, ft_lstnew(light));
		id++;
	}
}

void	init_lights(t_d_pars d_pars, t_data *data)
{
	ft_lstiter_param(d_pars.lst_pars, find_lights, data);
}

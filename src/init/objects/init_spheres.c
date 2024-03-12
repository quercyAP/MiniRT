/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spheres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:07:10 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	find_spheres(void *content, void *data)
{
	char		**tab_param;
	t_sphere	*sphere;
	static int	id = 1;

	tab_param = ((t_pars_line *)content)->token_tab;
	if (!ft_strcmp(tab_param[0], "sp"))
	{
		sphere = ft_calloc(sizeof(t_sphere), 1);
		*sphere = new_sphere(str_to_point3(tab_param[1]), ft_atod(tab_param[2]),
				str_to_color(tab_param[3]));
		sphere->id = id;
		ft_lstmixtadd_back(&((t_data *)data)->lst_object,
			ft_lstmixtnew(sphere, SPHERE));
		id++;
	}
}

void	init_spheres(t_d_pars d_pars, t_data *data)
{
	ft_lstiter_param(d_pars.lst_pars, find_spheres, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinders.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:06:18 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	find_cylinders(void *content, void *data)
{
	char		**tab_param;
	t_cylinder	*cylinder;
	static int	id = 1;

	tab_param = ((t_pars_line *)content)->token_tab;
	if (!ft_strcmp(tab_param[0], "cy"))
	{
		cylinder = ft_calloc(sizeof(t_cylinder), 1);
		*cylinder = new_cylinder(str_to_point3(tab_param[1]),
				str_to_vec3(tab_param[2]), (double [2]){ft_atod(tab_param[3]),
				ft_atod(tab_param[4])}, str_to_color(tab_param[5]));
		cylinder->id = id;
		ft_lstmixtadd_back(&((t_data *)data)->lst_object,
			ft_lstmixtnew(cylinder, CYLINDER));
		id++;
	}
}

void	init_cylinders(t_d_pars d_pars, t_data *data)
{
	ft_lstiter_param(d_pars.lst_pars, find_cylinders, data);
}

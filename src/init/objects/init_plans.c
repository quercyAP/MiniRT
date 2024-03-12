/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:06:55 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	find_plans(void *content, void *data)
{
	char		**tab_param;
	t_plan		*plan;
	static int	id = 1;

	tab_param = ((t_pars_line *)content)->token_tab;
	if (!ft_strcmp(tab_param[0], "pl"))
	{
		plan = ft_calloc(sizeof(t_plan), 1);
		*plan = new_plan(str_to_point3(tab_param[1]), str_to_vec3(tab_param[2]),
				str_to_color(tab_param[3]));
		plan->id = id;
		ft_lstmixtadd_back(&((t_data *)data)->lst_object,
			ft_lstmixtnew(plan, PLAN));
		id++;
	}
}

void	init_plans(t_d_pars d_pars, t_data *data)
{
	ft_lstiter_param(d_pars.lst_pars, find_plans, data);
}

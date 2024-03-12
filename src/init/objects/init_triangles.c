/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_triangles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:08:44 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	find_triangles(void *content, void *data)
{
	char		**tab_param;
	t_triangle	*triangle;
	static int	id = 1;

	tab_param = ((t_pars_line *)content)->token_tab;
	if (!ft_strcmp(tab_param[0], "tr"))
	{
		triangle = ft_calloc(sizeof(t_triangle), 1);
		*triangle = new_triangle(
				str_to_point3(tab_param[1]),
				str_to_point3(tab_param[2]),
				str_to_point3(tab_param[3]),
				str_to_color(tab_param[4]));
	triangle->id = id;
		ft_lstmixtadd_back(&((t_data *)data)->lst_object,
			ft_lstmixtnew(triangle, TRIANGLE));
		id++;
	}
}

void	init_triangles(t_d_pars d_pars, t_data *data)
{
	ft_lstiter_param(d_pars.lst_pars, find_triangles, data);
}

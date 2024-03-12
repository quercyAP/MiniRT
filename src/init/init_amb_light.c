/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_amb_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:04:17 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_amb_light(t_d_pars d_pars, t_data *data)
{
	t_list		*node_pars;
	char		**tab_param;

	node_pars = ft_lstfind_ref(d_pars.lst_pars, "A", find_pars_line);
	tab_param = ((t_pars_line *)node_pars->content)->token_tab;
	data->amb_light = new_amb_light(str_to_color(tab_param[2]),
			ft_atod(tab_param[1]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:04:34 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_camera(t_d_pars d_pars, t_data *data)
{
	t_camera	*c;
	t_list		*node_pars;
	char		**tab_param;

	node_pars = ft_lstfind_ref(d_pars.lst_pars, "C", find_pars_line);
	tab_param = ((t_pars_line *)node_pars->content)->token_tab;
	c = &(data->camera);
	c->origin = str_to_point3(tab_param[1]);
	c->vec_orient = vector_normalize(str_to_vec3(tab_param[2]));
	c->fov = ft_atod(tab_param[3]);
	c->image_ratio = (double)data->win_width / (double)data->win_height;
	c->viewport_width = 2.0;
	c->viewport_height = 1 / c->image_ratio * c->viewport_width;
	c->focal_length = (c->viewport_width / 2) / tan((c->fov / 2)
			* (M_PI / 180));
	cam_vec_calc(c);
}

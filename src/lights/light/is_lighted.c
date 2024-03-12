/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_lighted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/03 09:03:02 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	shade(double n_dot_l, t_list *tmp, double distance)
{
	return (((t_light *)tmp->content)->intensity * n_dot_l
		* 1 / (1 + distance / 8));
}

t_color	is_lighted(t_hit_rec *rec, t_data *data, t_color col)
{
	t_list	*tmp;
	bool	lighted;
	t_vec3	lx_dir;
	double	n_dot_l;
	double	distance;

	tmp = data->lst_light;
	while (tmp)
	{
		lx_dir = vector_normalize(vector_sub(((t_light *)tmp->content)->origin,
					rec->hit_pt));
		distance = fabs(vector_get_normale(vector_sub(((t_light *)tmp->content)
						->origin, rec->hit_pt)));
		n_dot_l = vector_dot(rec->normal, lx_dir);
		if (!is_shadowed(*rec, (t_light *)tmp->content, data->lst_object)
			&& n_dot_l > 0)
			col = color_add(col, color_mult(rec->color, color_dim(((t_light *)
								tmp->content)->color,
							shade(n_dot_l, tmp, distance))));
		tmp = tmp->next;
	}
	return (col);
}

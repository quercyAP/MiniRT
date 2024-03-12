/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:53:35 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	specular(t_hit_rec *rec, t_data *data, t_color diffuse_color)
{
	t_list	*tmp;
	t_vec3	in_vec;
	t_vec3	reflect_vec;
	double	len;
	double	spec;

	tmp = data->lst_light;
	while (tmp)
	{
		in_vec = vector_normalize(vector_sub(rec->hit_pt,
					((t_light *)tmp->content)->origin));
		len = 1.5f * -vector_dot(in_vec, rec->normal);
		reflect_vec = vector_normalize(vector_add(vector_mult(rec->normal, len),
					in_vec));
		spec = fmax(-vector_dot(reflect_vec, in_vec), 0);
		spec = powf(spec, 5);
		if (!is_shadowed(*rec, (t_light *)tmp->content, data->lst_object))
			diffuse_color = color_add(diffuse_color,
					color_dim(color_dim(((t_light *)tmp->content)->color,
							((t_light *)tmp->content)->intensity), spec));
		tmp = tmp->next;
	}
	return (diffuse_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 16:05:02 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_shadowed(t_hit_rec rec, t_light *light, t_list_mixt *obj)
{
	t_hit_rec	shadow_rec;
	double		light_dist;	
	t_vec3		rec_to_light;

	rec_to_light = vector_sub(light->origin, rec.hit_pt);
	light_dist = vector_get_normale(rec_to_light);
	if (get_hit_rec(obj, new_ray(vector_add(rec.hit_pt,
					vector_mult(rec.normal, 1e-4)),
				vector_normalize(rec_to_light)), &shadow_rec, light_dist)
		&& shadow_rec.dist < light_dist)
		return (true);
	else
		return (false);
}

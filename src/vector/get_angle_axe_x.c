/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_angle_axe_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:43:53 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_angle_axe_x(t_vec3 vec)
{
	t_vec3	vec_z;

	vec_z = new_vec3(0, 0, 1);
	return (acos(vector_dot(vec, vec_z) / (vector_get_normale(vec)
				* vector_get_normale(vec_z))));
}

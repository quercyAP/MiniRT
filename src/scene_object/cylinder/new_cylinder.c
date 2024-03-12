/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:22:30 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	new_cylinder(t_point3 origin, t_vec3 vec_axe, double size[2],
	t_color color)
{
	t_cylinder	ret;

	ret.type = CYLINDER;
	ret.vec_axis = vector_normalize(vec_axe);
	ret.origin = origin;
	ret.diameter = size[0];
	ret.radius = ret. diameter / 2;
	ret.height = size[1];
	ret.color = color;
	return (ret);
}

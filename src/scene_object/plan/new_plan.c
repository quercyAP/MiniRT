/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:24:23 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plan	new_plan(t_point3 origin, t_vec3 vec_orient, t_color color)
{
	t_plan	plan;

	plan.type = PLAN;
	plan.color = color;
	plan.origin = origin;
	plan.vec_orient = vector_normalize(vec_orient);
	return (plan);
}

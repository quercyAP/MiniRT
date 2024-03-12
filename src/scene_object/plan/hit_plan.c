/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:28:26 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	ret(t_hit_rec *rec, t_plan	*plan, t_ray ray, t_vec3 normal)
{
	rec->inside = false;
	rec->hit_pt = point_at_ray(ray, rec->dist);
	if (vector_dot(normal, ray.vec_dir) > 0)
		normal = vector_mult(normal, -1);
	rec->normal = normal;
	rec->color = plan->color;
	return (true);
}

bool	hit_plan(t_plan	*plan, t_ray ray, t_hit_rec *rec, double t_max)
{
	t_vec3		normal;
	t_vec3		perpan;
	double		t;

	if (plan->vec_orient.x == 0 && plan->vec_orient.y == 0
		&& plan->vec_orient.z == 1)
	{
		perpan = vector_rot_axe_x(plan->vec_orient, M_PI_2);
		perpan = vector_rot_axe_z(perpan, M_PI_2);
	}
	else
		perpan = vector_rot_axe_z(plan->vec_orient, M_PI_2);
	perpan.z = 0;
	normal = vector_normalize(vector_cross(perpan, plan->vec_orient));
	if (vector_dot(normal, ray.vec_dir) == 0)
		return (false);
	t = vector_dot(vector_from_2pts(ray.origin, plan->origin),
			normal) / vector_dot(ray.vec_dir, normal);
	if (t > 0 && t < t_max)
	{
		rec->dist = t;
		return (ret(rec, plan, ray, normal));
	}
	return (false);
}

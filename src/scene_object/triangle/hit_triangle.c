/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/03 09:29:03 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	calc_barycentric(t_triangle *triangle,
	t_point3 pt, double *u, double *v)
{
	t_vec3	v01;
	double	area;
	t_vec3	p1_to_pt;
	t_vec3	cross_compare;

	v01 = vector_from_2pts(triangle->pt0, triangle->pt1);
	area = vector_get_normale(triangle->normal) / 2;
	p1_to_pt = vector_from_2pts(triangle->pt1, pt);
	cross_compare = vector_cross(v01, vector_from_2pts(triangle->pt0, pt));
	if (vector_dot(triangle->normal, cross_compare) < 0)
		return (false);
	*u = (vector_get_normale(cross_compare) / 2) / area;
	cross_compare = vector_cross(vector_from_2pts(triangle->pt1,
				triangle->pt2), p1_to_pt);
	if (vector_dot(triangle->normal, cross_compare) < 0)
		return (false);
	*v = (vector_get_normale(cross_compare) / 2) / area;
	return (vector_dot(triangle->normal, cross_compare));
}

static bool	is_inside_triangle(t_triangle *triangle, t_point3 pt)
{
	double	u;
	double	v;

	if (!calc_barycentric(triangle, pt, &u, &v))
		return (false);
	if (u + v > 1)
		return (false);
	return (true);
}

bool	hit_triangle(t_ray ray, t_triangle *trgle,
	double t_max, t_hit_rec *rec)
{
	double		porj_r_to_n;
	double		t;
	t_point3	hit;

	porj_r_to_n = vector_dot(ray.vec_dir, trgle->normal);
	if (fabs(porj_r_to_n) < 1e-6)
		return (false);
	t = (vector_dot(trgle->pt1, trgle->normal) - vector_dot(ray.origin,
				trgle->normal)) / porj_r_to_n;
	if (t < 0 || t > t_max)
		return (false);
	hit = point_at_ray(ray, t);
	if (!is_inside_triangle(trgle, hit))
		return (false);
	rec->dist = t;
	rec->hit_pt = hit;
	rec->normal = vector_normalize(trgle->normal);
	rec->color = trgle->color;
	return (true);
}

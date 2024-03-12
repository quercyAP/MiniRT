/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/03 09:26:30 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	calc_discriminant(t_cylinder *cylinder, t_ray ray, double t_max,
	t_vec3 *calc)
{
	t_triple	equat;
	t_vec3		vecdir;

	vecdir = vector_sub(ray.origin, cylinder->origin);
	equat.a = vector_dot(ray.vec_dir, ray.vec_dir)
		- pow(vector_dot(ray.vec_dir, cylinder->vec_axis), 2);
	equat.b = 2 * (vector_dot(ray.vec_dir, vecdir)
			- vector_dot(ray.vec_dir, cylinder->vec_axis)
			* vector_dot(vecdir, cylinder->vec_axis));
	equat.c = vector_dot(vecdir, vecdir)
		- pow(vector_dot(vecdir, cylinder->vec_axis), 2)
		- pow(cylinder->radius, 2);
	calc->x = equat.b * equat.b - 4 * equat.a * equat.c;
	if (calc->x < 0)
		return (false);
	calc->y = (-equat.b - sqrt(calc->x)) / (2 * equat.a);
	calc->z = (-equat.b + sqrt(calc->x)) / (2 * equat.a);
	calc->x = t_max;
	return (true);
}

static void	record_calc(t_hit_rec *rec, t_ray ray, t_cylinder *cylinder,
	double dist)
{
	t_vec3	hit_to_origin;
	double	proj_on_axis;
	t_vec3	proj_point;
	t_vec3	hit_proj_pt;

	rec->inside = false;
	rec->dist = dist;
	rec->hit_pt = point_at_ray(ray, rec->dist);
	hit_to_origin = vector_from_2pts(cylinder->origin, rec->hit_pt);
	proj_on_axis = vector_dot(hit_to_origin, cylinder->vec_axis);
	proj_point = vector_mult(cylinder->vec_axis, proj_on_axis);
	proj_point = vector_add(cylinder->origin, proj_point);
	hit_proj_pt = vector_sub(rec->hit_pt, proj_point);
	rec->normal = vector_normalize(vector_div(hit_proj_pt, cylinder->radius));
	if (vector_dot(ray.vec_dir, rec->normal) > 0)
		rec->normal = vector_mult(rec->normal, -1);
	rec->color = cylinder->color;
}

static double	discriminer(t_vec3 discri)
{
	if (discri.y < discri.z)
		return (discri.y);
	else
		return (discri.z);
}

static bool	calc_hit_dist(t_cylinder *cylinder, t_hit_rec *rec, t_ray ray,
	t_vec3 discri)
{
	double	dist1;
	double	dist2;
	double	min_x;

	dist1 = vector_dot(cylinder->vec_axis,
			vector_sub(point_at_ray(ray, discri.y), cylinder->origin));
	dist2 = vector_dot(cylinder->vec_axis,
			vector_sub(point_at_ray(ray, discri.z), cylinder->origin));
	if (!((dist1 >= (0 - cylinder->height / 2) && dist1 <= cylinder->height / 2
				&& discri.y > EPSILON && discri.y < discri.x)
			|| (dist2 >= (0 - cylinder->height / 2)
				&& dist2 <= cylinder->height / 2
				&& discri.z > EPSILON && discri.z < discri.x)))
		return (false);
	if (dist1 >= (0 - cylinder->height / 2) && dist1 <= cylinder->height / 2
		&& discri.y > EPSILON && dist2 >= (0 - cylinder->height / 2)
		&& dist2 <= cylinder->height / 2 && discri.z > EPSILON)
		min_x = discriminer(discri);
	else if (dist1 >= (0 - cylinder->height / 2)
		&& dist1 <= cylinder->height / 2 && discri.y > EPSILON)
		min_x = discri.y;
	else
		min_x = discri.z;
	record_calc(rec, ray, cylinder, min_x);
	return (true);
}

bool	hit_cylinder(t_cylinder *cylinder, t_ray ray, t_hit_rec *rec,
	double t_max)
{
	t_vec3	calc;

	if (!calc_discriminant(cylinder, ray, t_max, &calc))
		return (false);
	if (!calc_hit_dist(cylinder, rec, ray, calc))
		return (false);
	return (true);
}

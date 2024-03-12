/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/03 09:23:03 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// equation quadratique (ax)² + bx + c = 0	
// x = distance du point dintersection ou root
// a, b, c constante determiner par les proprieter de la sphere
// a = norme au carre du vecteur de direction du rayon

// on sait que la forme parametrique du rayon = O + tD
// ou O = origin du rayon, D est la direction du rayon et t est
// un point sur le rayon
// avec P les coordonner d'un point sur la surface de la sphere on peut dire 
// que P^2 - R^2 = 0
// on a donc le point d'intersection apartenant a la sphere (O + tD)^2 - R^2 = 0
// en develloper sa donne (O + tD).(O + tD) - R^2 = 0
// et aussi (O.O) + (O.tD) + (tD.O) + (t.D.t.D) - R^2 = 0
// et puis O.O + 2t(O.D) + t^2(D.D) - R^2 = 0 qui est une equation quqdratique 
// ou a = D^2 , b = 2OD et c = O^2 - R^2

#include "minirt.h"

static void	fillerrr(t_hit_rec *rec, double root, t_sphere *sphere, t_ray ray)
{
	rec->dist = root;
	rec->inside = false;
	rec->hit_pt = point_at_ray(ray, rec->dist);
	rec->normal = vector_normalize(vector_div(vector_sub(rec->hit_pt,
					sphere->origin), sphere->radius));
}

bool	hit_sphere(t_sphere *sphere, t_ray ray, t_hit_rec *rec, double t_max)
{
	t_triple	_;
	double		discriminant;
	double		root;
	t_vec3		vec_dir;

	vec_dir = vector_from_2pts(sphere->origin, ray.origin);
	_.a = vector_dot(ray.vec_dir, ray.vec_dir);
	_.b = 2.0 * vector_dot(vec_dir, ray.vec_dir);
	_.c = vector_dot(vec_dir, vec_dir) - (sphere->radius * sphere->radius);
	discriminant = _.b * _.b - 4 * _.a * _.c;
	if (discriminant < 0)
		return (false);
	root = (-_.b - sqrt(discriminant)) / (2.0 * _.a);
	if (root < 0 || t_max < root)
	{
		root = (-_.b + sqrt(discriminant)) / (2.0 * _.a);
		if (root < 0 || t_max < root)
			return (false);
	}
	fillerrr(rec, root, sphere, ray);
	if (vector_dot(ray.vec_dir, rec->normal) > 0)
		rec->normal = vector_mult(rec->normal, -1);
	rec->color = sphere->color;
	return (true);
}

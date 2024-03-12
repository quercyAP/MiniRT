/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_rec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:49:29 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_hitted_closest(int	*hitted, double *closest, double dist)
{
	*hitted = true;
	*closest = dist;
}

bool	get_hit_rec(t_list_mixt *lst_obj, t_ray ray, t_hit_rec *rec,
	double closest)
{
	t_list_mixt		*tmp;
	int				hitted;

	tmp = lst_obj;
	hitted = false;
	while (tmp)
	{
		if (tmp->type == PLAN
			&& hit_plan(((t_plan *)tmp->content), ray, rec, closest))
			set_hitted_closest(&hitted, &closest, rec->dist);
		if (tmp->type == CYLINDER
			&& hit_cylinder(((t_cylinder *)tmp->content), ray, rec, closest))
			set_hitted_closest(&hitted, &closest, rec->dist);
		if (tmp->type == SPHERE
			&& hit_sphere(((t_sphere *)tmp->content), ray, rec, closest))
			set_hitted_closest(&hitted, &closest, rec->dist);
		if (tmp->type == TRIANGLE
			&& hit_triangle(ray, ((t_triangle *)tmp->content), closest, rec))
			set_hitted_closest(&hitted, &closest, rec->dist);
		tmp = tmp->next;
	}
	return (hitted);
}

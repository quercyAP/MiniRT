/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:01:14 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_cylinder(void *cylinder)
{
	t_cylinder	c;

	c = *((t_cylinder *)cylinder);
	printf("🟣 *** CYLINDER n°%i ***\n", c.id);
	printf(" Diameter :\t%.3lf\n", c.diameter);
	printf(" Hauteur :\t%.3lf\n", c.height);
	print_color(c.color, NULL);
	print_point3(c.origin, "Origin");
	print_vec3(c.vec_axis, "Axis");
	print_angle(c.vec_axis, "Axis");
}

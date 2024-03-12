/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 15:10:22 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_object(void *object, int type)
{
	if (type == TRIANGLE)
		print_triangle(object);
	else if (type == CYLINDER)
		print_cylinder(object);
	else if (type == SPHERE)
		print_sphere(object);
	else if (type == PLAN)
		print_plan(object);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/19 11:22:37 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	new_sphere(t_point3 origin, double diameter, t_color color)
{
	t_sphere	sphere;

	sphere.type = SPHERE;
	sphere.origin = origin;
	sphere.diameter = diameter;
	sphere.radius = diameter / 2;
	sphere.color = color;
	return (sphere);
}

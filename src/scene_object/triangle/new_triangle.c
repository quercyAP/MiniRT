/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:42:33 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_triangle	new_triangle(t_point3 pt0, t_point3 pt1, t_point3 pt2,
	t_color color)
{
	t_triangle	triangle;
	t_vec3		v01;
	t_vec3		v02;

	triangle.type = TRIANGLE;
	triangle.pt0 = pt0;
	triangle.pt1 = pt1;
	triangle.pt2 = pt2;
	triangle.color = color;
	v01 = vector_from_2pts(pt0, pt1);
	v02 = vector_from_2pts(pt0, pt2);
	triangle.normal = vector_cross(v01, v02);
	return (triangle);
}

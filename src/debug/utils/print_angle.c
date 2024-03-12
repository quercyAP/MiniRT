/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_angle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/26 14:27:55 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_angle(t_vec3 vec_orient, char *str)
{
	double	a_x;
	double	a_z;

	a_x = get_angle_axe_x(vec_orient) * 180 / M_PI;
	if (vec_orient.y > 0)
	{
		if (vec_orient.x == 0)
			a_z = 0;
		else
			a_z = (get_angle_axe_z(vec_orient) - M_PI_2) * -180 / M_PI;
	}
	else
	{
		if (vec_orient.x == 0)
			a_z = 0;
		else
			a_z = (get_angle_axe_z(vec_orient) + M_PI_2) * 180 / M_PI;
	}
	printf(" Ang %s :\tX:%.1lf° Y:0.0° Z:%.1lf°\n", str, a_x, a_z);
}

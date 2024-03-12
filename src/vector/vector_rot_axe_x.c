/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rot_axe_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:46:27 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vector_rot_axe_x(t_vec3	vec, double angle)
{
	t_vec3	ret;

	ret.x = vec.x;
	ret.y = vec.z * sin(angle) + vec.y * cos(angle);
	ret.z = vec.z * cos(angle) - vec.y * sin(angle);
	return (ret);
}

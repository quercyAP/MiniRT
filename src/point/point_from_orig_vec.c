/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_from_orig_vec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/12 14:29:07 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	point_from_orig_vec(t_point3 origin, t_vec3 vec)
{
	t_point3	ret;

	ret.x = vec.x + origin.x;
	ret.y = vec.y + origin.y;
	ret.z = vec.z + origin.z;
	return (ret);
}

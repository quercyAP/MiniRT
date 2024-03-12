/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/12 09:41:18 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vector_cross(t_vec3 vec_a, t_vec3 vec_b)
{
	t_vec3	ret;

	ret.x = vec_a.y * vec_b.z - vec_a.z * vec_b.y;
	ret.y = vec_a.z * vec_b.x - vec_a.x * vec_b.z;
	ret.z = vec_a.x * vec_b.y - vec_a.y * vec_b.x;
	return (ret);
}

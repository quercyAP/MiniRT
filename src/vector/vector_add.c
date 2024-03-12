/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/12 09:41:03 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vector_add(t_vec3 vec_a, t_vec3 vec_b)
{
	t_vec3	ret;

	ret.x = vec_a.x + vec_b.x;
	ret.y = vec_a.y + vec_b.y;
	ret.z = vec_a.z + vec_b.z;
	return (ret);
}

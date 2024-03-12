/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ray_at_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:55:29 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	new_ray_at_pixel(t_data data, int x, int y)
{
	double		u;
	double		v;
	t_camera	c;
	t_vec3		offset;

	u = (double)x / (data.win_width - 1);
	v = -(double)y / (data.win_height - 1);
	c = data.camera;
	offset = vector_add(vector_mult(c.vec_vp_horiz, u),
			vector_mult(c.vec_vp_vert, v));
	return (new_ray(c.origin, vector_mult(vector_normalize(vector_from_2pts(
						c.origin, point_from_orig_vec(c.vp_ulc, offset))),
				c.focal_length)));
}

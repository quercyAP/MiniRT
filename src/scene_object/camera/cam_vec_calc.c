/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_vec_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:04:17 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_vec_calc(t_camera *cam)
{
	t_vec3	vec_axe_cam;

	vec_axe_cam = vector_mult(cam->vec_orient, cam->focal_length);
	cam->x_axis_rot = get_angle_axe_x(vec_axe_cam);
	cam->z_axis_rot = get_angle_axe_z(vec_axe_cam);
	if (cam->vec_orient.x == 0 && cam->vec_orient.y == 0
		&& cam->vec_orient.z > 0)
	{
		cam->vec_vp_horiz = vector_rot_axe_x(cam->vec_orient, M_PI_2);
		cam->vec_vp_horiz = vector_rot_axe_z(cam->vec_vp_horiz, M_PI_2);
	}
	else
		cam->vec_vp_horiz = vector_rot_axe_z(cam->vec_orient, M_PI_2);
	cam->vec_vp_horiz.z = 0;
	cam->vec_vp_horiz = vector_mult(vector_normalize(cam->vec_vp_horiz),
			cam->viewport_width);
	cam->vec_vp_vert = vector_mult(vector_normalize(vector_cross(
					cam->vec_vp_horiz, cam->vec_orient)), cam->viewport_height);
	cam->vp_center = point_from_orig_vec(cam->origin, vec_axe_cam);
	cam->vp_ulc = point_from_orig_vec(cam->vp_center, vector_add(
				vector_div(cam->vec_vp_horiz, -2.0),
				vector_div(cam->vec_vp_vert, 2.0)));
}

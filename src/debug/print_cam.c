/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/26 14:25:37 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_cam(t_camera camera)
{
	printf("🎥 *** CAMERA ***\n");
	printf("Image ratio :\t%.2lf\n", camera.image_ratio);
	printf("FOV :\t%.2lf°\n", camera.fov);
	print_point3(camera.origin, "Origin");
	print_vec3(camera.vec_orient, "Orient");
	print_angle(camera.vec_orient, "Orient");
}

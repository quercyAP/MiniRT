/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:04:29 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_translate(t_camera *cam, double delta_x, double delta_y,
	double delta_z)
{
	cam->origin.x += delta_x;
	cam->origin.y += delta_y;
	cam->origin.z += delta_z;
	cam_vec_calc(cam);
}

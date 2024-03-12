/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 08:40:58 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init(t_d_pars d_pars, t_data *data)
{
	ft_memset(data, 0, sizeof(*data));
	init_mlx(data);
	init_bg(data);
	init_all_pixel(data);
	init_object(d_pars, data);
	init_amb_light(d_pars, data);
	init_lights(d_pars, data);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	init_camera(d_pars, data);
}

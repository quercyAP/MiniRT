/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 15:46:04 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_data *data)
{
	data->win_width = WIN_WIDTH;
	data->win_height = WIN_HEIGHT;
	data->mlx = mlx_init(data->win_width, data->win_height, "MINI RT", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	data->image = mlx_new_image(data->mlx, data->win_width, data->win_height);
}

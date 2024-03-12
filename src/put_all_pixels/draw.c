/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:44:37 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_current_pix(int x, int y, t_data *data)
{
	t_hit_rec	rec;
	t_color		diffuse_color;

	diffuse_color = color_dim(data->amb_light.color, data->amb_light.intensity);
	if (get_hit_rec(data->lst_object, new_ray_at_pixel(*data, x, y), &rec,
			INT32_MAX))
		data->all_pixel[y][x] = color_add(is_lighted(&rec, data, diffuse_color),
				specular(&rec, data, diffuse_color));
	else
		data->all_pixel[y][x] = data->bg[y][x];
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			set_current_pix(x, y, data);
			x++;
		}
		y++;
	}
	put_all_pixels(data);
}

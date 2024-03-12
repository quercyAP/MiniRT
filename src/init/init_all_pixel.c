/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/19 13:07:17 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_all_pixel(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	data->all_pixel = ft_calloc(sizeof(t_color *), (data->win_height));
	while (y < data->win_height)
	{
		x = 0;
		(data->all_pixel)[y] = ft_calloc(sizeof(t_color), (data->win_width));
		while (x < data->win_width)
		{
			data->all_pixel[y][x] = data->bg[y][x];
			x++;
		}
		y++;
	}
	put_all_pixels(data);
}

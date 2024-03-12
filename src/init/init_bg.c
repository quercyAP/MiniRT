/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 09:55:28 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_bg(t_data *data)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	y = 0;
	data->bg = ft_calloc(sizeof(t_color *), (data->win_height));
	while (y < data->win_height)
	{
		x = 0;
		(data->bg)[y] = ft_calloc(sizeof(t_color), (data->win_width));
		while (x < data->win_width)
		{
			((data->bg)[y][x]).c = 0x000000FF;
			x++;
		}
		y++;
	}
}

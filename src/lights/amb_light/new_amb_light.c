/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_amb_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/19 09:56:04 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_amb_light	new_amb_light(t_color color, double intensity)
{
	t_amb_light	ret;

	ret.color = color;
	ret.intensity = intensity;
	return (ret);
}

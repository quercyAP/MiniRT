/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_dim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 13:58:52 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_dim(t_color color, double intensity)
{
	t_color	ret;
	double	r;
	double	g;
	double	b;

	r = (double)color.abgr.r;
	g = (double)color.abgr.g;
	b = (double)color.abgr.b;
	r *= intensity;
	g *= intensity;
	b *= intensity;
	ret = color;
	ret.abgr.r = (unsigned char)r;
	ret.abgr.g = (unsigned char)g;
	ret.abgr.b = (unsigned char)b;
	return (ret);
}

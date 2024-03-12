/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:00:24 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_mult(t_color c1, t_color c2)
{
	t_color	ret;

	ret.abgr.a = c1.abgr.a;
	ret.abgr.r = c1.abgr.r * c2.abgr.r / 255;
	ret.abgr.g = c1.abgr.g * c2.abgr.g / 255;
	ret.abgr.b = c1.abgr.b * c2.abgr.b / 255;
	return (ret);
}

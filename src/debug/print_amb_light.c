/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_amb_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/26 14:25:20 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_amb_light(t_amb_light amb_light)
{
	printf("💡 *** AMBIANCE LIGHT ***\n");
	print_color(amb_light.color, "Color");
	printf(" Intensity :\t%.2lf\n", amb_light.intensity);
}

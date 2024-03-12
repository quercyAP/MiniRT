/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:01:23 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_light(void *light)
{
	t_light	l;

	l = *((t_light *)light);
	printf("🔦 *** LIGHT n°%i ***\n", l.id);
	print_color(l.color, NULL);
	printf(" Intensity :\t%.2lf\n", l.intensity);
	print_point3(l.origin, "Origin");
}

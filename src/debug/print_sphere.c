/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:02:23 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_sphere(void *sphere)
{
	t_sphere	s;

	s = *((t_sphere *)sphere);
	printf("🔵 *** SPHERE n°%i ***\n", s.id);
	printf(" Diameter :\t%.3lf\n", s.diameter);
	print_color(s.color, NULL);
	print_point3(s.origin, "Origin");
}

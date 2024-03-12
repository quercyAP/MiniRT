/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:02:09 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_plan(void *plan)
{
	t_plan	p;

	p = *((t_plan *)plan);
	printf("🟢 *** PLAN n°%i ***\n", p.id);
	print_color(p.color, NULL);
	print_point3(p.origin, "Origin");
	print_vec3(p.vec_orient, "Orient");
	print_angle(p.vec_orient, "Orient");
}

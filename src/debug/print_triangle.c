/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:02:26 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_triangle(void *triangle)
{
	t_triangle	t;

	t = *((t_triangle *)triangle);
	printf("🟠 *** TRIANGLE n°%i ***\n", t.id);
	print_color(t.color, NULL);
	print_point3(t.pt0, "0");
	print_point3(t.pt1, "1");
	print_point3(t.pt2, "2");
}

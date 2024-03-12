/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 16:00:10 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_TRIANGLE_H
# define HIT_TRIANGLE_H

bool	hit_triangle(t_ray ray, t_triangle *trgle, double t_max,
			t_hit_rec *rec);

#endif

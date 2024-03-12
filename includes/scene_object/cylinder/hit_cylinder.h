/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:59:30 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_CYLINDER_H
# define HIT_CYLINDER_H

bool	hit_cylinder(t_cylinder *cylinder, t_ray ray, t_hit_rec *rec,
			double t_max);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 16:00:01 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_SPHERE_H
# define HIT_SPHERE_H

bool	hit_sphere(t_sphere *sphere, t_ray ray, t_hit_rec *rec, double t_max);

#endif

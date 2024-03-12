/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:58:30 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECULAR_H
# define SPECULAR_H

t_color	specular(t_hit_rec *rec, t_data *data, t_color diffuse_color);

#endif

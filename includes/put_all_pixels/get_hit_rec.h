/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hit_rec.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:58:20 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_HIT_REC_H
# define GET_HIT_REC_H

bool	get_hit_rec(t_list_mixt *lst_obj, t_ray ray, t_hit_rec *rec,
			double closest);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:33:08 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camera_check(t_pars_line pars_line)
{
	if (pars_line.token_tab[1] == NULL)
		return ((void)add_error(pars_line.d_pars, TOO_FEW_PARAM_ER,
				"Camera", pars_line.id));
	coord_check(pars_line.d_pars, pars_line.token_tab[1], pars_line.id);
	if (pars_line.token_tab[2] == NULL)
		return ((void)add_error(pars_line.d_pars, TOO_FEW_PARAM_ER,
				"Camera", pars_line.id));
	vec_check(pars_line.d_pars, pars_line.token_tab[2], pars_line.id);
	if (pars_line.token_tab[3] == NULL)
		return ((void)add_error(pars_line.d_pars, TOO_FEW_PARAM_ER,
				"Camera", pars_line.id));
	angle_check(pars_line.d_pars, pars_line.token_tab[3], pars_line.id);
	if (pars_line.token_tab[4] != NULL)
		return ((void)add_error(pars_line.d_pars, TOO_MANY_PARAM_ER,
				"Camera", pars_line.id));
}

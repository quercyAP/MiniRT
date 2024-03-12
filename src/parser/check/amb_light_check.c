/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_light_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:32:38 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	amb_light_check(t_pars_line pars_line)
{
	if (pars_line.token_tab[1] == NULL)
		return ((void)add_error(pars_line.d_pars, TOO_FEW_PARAM_ER,
				"Ambiance light", pars_line.id));
	intensity_check(pars_line.d_pars, pars_line.token_tab[1], pars_line.id);
	if (pars_line.token_tab[2] == NULL)
		return ((void)add_error(pars_line.d_pars, TOO_FEW_PARAM_ER,
				"Ambiance light", pars_line.id));
	color_check(pars_line.d_pars, pars_line.token_tab[2], pars_line.id);
	if (pars_line.token_tab[3] != NULL)
		return ((void)add_error(pars_line.d_pars, TOO_MANY_PARAM_ER,
				"Ambiance light", pars_line.id));
}

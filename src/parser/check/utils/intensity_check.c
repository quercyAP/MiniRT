/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:37:58 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	intensity_check(t_d_pars *d_pars, char *str, int line_nb)
{
	char	*msg;

	msg = ft_strjoin("intensity[0.0,1.0] -> ", str);
	if (ft_strlen(str) > 3)
		add_error(d_pars, INVALID_LENGTH_ER, msg, line_nb);
	if (ft_isdigit(str[0]))
	{
		if (str[0] != '1' && str[0] != '0')
			return (add_error(d_pars, INVALID_RANGE_ER, msg, line_nb));
	}
	else
		return (add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	if (!str[1])
		return (0);
	if (str[1] && str[1] != '.')
		return (add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	if (!str[2])
		return (add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	if (!ft_isdigit(str[2]))
		return (add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	if (str[0] == '1' && str[2] != '0')
		return (add_error(d_pars, INVALID_RANGE_ER, msg, line_nb));
	free(msg);
	return (0);
}

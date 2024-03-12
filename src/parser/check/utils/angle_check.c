/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:35:34 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	double_check(t_d_pars *d_pars, char *str, int line_nb, char *msg)
{
	int				i;
	int				len;
	unsigned int	number;

	i = 0;
	len = ft_strlen(str);
	while (i < len && ft_isdigit(str[i]) && i < 3)
		i++;
	if (i == 0)
		return ((void)add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	if (len != i)
		return ((void)add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	number = ft_atoi(str);
	if (number < 1 || number > 179)
		return ((void)add_error(d_pars, INVALID_RANGE_ER, msg, line_nb));
}

void	angle_check(t_d_pars *d_pars, char *str, int line_nb)
{
	char	*msg;

	msg = ft_strjoin("angle ]0,180[ -> ", str);
	double_check(d_pars, str, line_nb, msg);
	free(msg);
}

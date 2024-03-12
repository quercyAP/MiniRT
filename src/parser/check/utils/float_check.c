/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:37:48 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	double_check(t_d_pars *d_pars, char *str, int line_nb, char *msg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len && ft_isdigit(str[i]) && i < 2)
		i++;
	if (i == 0)
		return ((void)add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	else if (i == 1 && str[1] && str[1] == '.')
	{
		i++;
		while (i < len && ft_isdigit(str[i]) && i < 8)
			i++;
	}
	else if (str[i] && str[i] == '.')
	{
		i++;
		while (i < len && ft_isdigit(str[i]) && i < 9)
			i++;
	}
	if (len != i)
		return ((void)add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
}

void	float_check(t_d_pars *d_pars, char *str, int line_nb)
{
	char	*msg;
	int		i;

	msg = ft_strjoin("unsigned float [0 - 99.999999] -> ", str);
	double_check(d_pars, str, line_nb, msg);
	free(msg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:39:40 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	double_check(t_d_pars *d_pars, char *str, int nb_l, char *msg)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] && ft_isdigit(str[0]))
		;
	else
		return ((void)add_error(d_pars, INVALID_FORMAT_ER, msg, nb_l));
	if (str[0] == '0' || str[0] == '1')
		i++;
	else
		return ((void)add_error(d_pars, INVALID_RANGE_ER, msg, nb_l));
	if (str[1] && str[1] == '.')
	{
		i++;
		while (i < len && ft_isdigit(str[i]) && i < 5)
		{
			if (str[0] == '1' && str[i] != '0')
				return ((void)add_error(d_pars, INVALID_RANGE_ER, msg, nb_l));
			i++;
		}
	}
	if (len != i)
		return ((void)add_error(d_pars, INVALID_FORMAT_ER, msg, nb_l));
}

void	vec_check(t_d_pars *d_pars, char *str, int line_nb)
{
	char	*msg;
	char	**tab_double;
	int		i;

	i = 0;
	tab_double = ft_split(str, ',');
	msg = ft_strjoin("vector [-1.000 - 1.000] -> ", str);
	if (ft_strtab_len(tab_double) == 3)
	{
		while (tab_double[i])
		{
			if (tab_double[i][0] == '-')
				double_check(d_pars, tab_double[i] + 1, line_nb, msg);
			else
				double_check(d_pars, tab_double[i], line_nb, msg);
			i++;
		}
	}
	else
	{
		add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb);
	}
	ft_strtab_clear(tab_double);
	free(msg);
}

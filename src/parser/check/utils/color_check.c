/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:36:36 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	int_check(t_d_pars *d_pars, char *str, int line_nb, char *msg)
{
	int				len;
	int				i;
	unsigned int	number;

	i = 0;
	len = ft_strlen(str);
	while (ft_isdigit(str[i]))
		i++;
	if (len != i)
		return ((void)add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb));
	number = ft_atoi(str);
	if (number > 255)
		return ((void)add_error(d_pars, INVALID_RANGE_ER, msg, line_nb));
}

void	color_check(t_d_pars *d_pars, char *str, int line_nb)
{
	char	*msg;
	char	**tab_int;
	int		i;

	i = 0;
	tab_int = ft_split(str, ',');
	msg = ft_strjoin("color RGB [0-255] -> ", str);
	if (ft_strtab_len(tab_int) == 3)
	{
		while (tab_int[i])
		{
			int_check(d_pars, tab_int[i], line_nb, msg);
			i++;
		}
	}
	else
	{
		add_error(d_pars, INVALID_FORMAT_ER, msg, line_nb);
	}
	ft_strtab_clear(tab_int);
	free(msg);
}

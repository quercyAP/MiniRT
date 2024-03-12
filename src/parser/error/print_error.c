/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:42:18 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(t_d_pars d_pars)
{
	t_list_error	*tmp;

	tmp = d_pars.lst_error;
	if (tmp)
	{
		while (tmp)
		{
			ft_putstr_fd(FT_RED, 2);
			ft_putstr_fd(tmp->arg, 2);
			ft_putstr_fd(" : ", 2);
			ft_putstr_fd(d_pars.strerror_tab[tmp->error], 2);
			if (tmp->line_nb)
			{
				ft_putstr_fd(" at line ", 2);
				ft_putstr_fd(ft_itoa(tmp->line_nb), 2);
			}
			else
				ft_putstr_fd(" in file", 2);
			ft_putstr_fd("\n", 2);
			ft_putstr_fd(FT_CLEAR, 2);
			tmp = tmp->next;
		}
	}
}

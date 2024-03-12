/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_d_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:03:41 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_lst_error(t_list_error **lst_error)
{
	t_list_error	*tmp;

	if (!lst_error)
		return ;
	while ((*lst_error))
	{
		tmp = (*lst_error)->next;
		free((*lst_error)->arg);
		free(*lst_error);
		(*lst_error) = tmp;
	}
}

static void	pars_line_lst_clear(void *content)
{
	t_pars_line	*l;

	l = (t_pars_line *)content;
	free(l->raw_line);
	ft_strtab_clear(l->token_tab);
	free(l);
}

void	free_d_pars(t_d_pars *d_pars)
{
	ft_strtab_clear(d_pars->strerror_tab);
	ft_lstclear(&(d_pars->lst_pars), pars_line_lst_clear);
	free_lst_error(&(d_pars->lst_error));
}

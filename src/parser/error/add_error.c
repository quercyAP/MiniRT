/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:40:45 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_list_error	*error_lstlast(t_list_error *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

static void	error_lstadd_back(t_list_error **lst, t_list_error *new)
{
	t_list_error	*tmp;

	tmp = (*lst);
	if (!lst)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
	{
		tmp = error_lstlast(*(lst));
		tmp->next = new;
	}
}

static t_list_error	*error_lstnew(enum e_pars_error error, char *arg,
	int line_nb)
{
	t_list_error	*ret;

	ret = ft_calloc(1, sizeof(t_list_error));
	if (!ret)
		return (NULL);
	ret->arg = ft_strdup(arg);
	ret->error = error;
	ret->line_nb = line_nb;
	return (ret);
}

int	add_error(t_d_pars *d_pars, enum e_pars_error error, char *arg, int line_nb)
{
	error_lstadd_back(&(d_pars->lst_error), error_lstnew(error, arg, line_nb));
	return (-1);
}

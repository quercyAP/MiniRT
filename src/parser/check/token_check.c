/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:35:11 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	t_check(void *line)
{
	t_pars_line	*l;

	l = (t_pars_line *)line;
	if (!ft_strcmp(l->token_tab[0], "A"))
		l->d_pars->nb_amblight += 1;
	else if (!ft_strcmp(l->token_tab[0], "C"))
		l->d_pars->nb_cam += 1;
	else if (!ft_strcmp(l->token_tab[0], "L"))
		;
	else if (!ft_strcmp(l->token_tab[0], "sp"))
		;
	else if (!ft_strcmp(l->token_tab[0], "pl"))
		;
	else if (!ft_strcmp(l->token_tab[0], "cy"))
		;
	else if (!ft_strcmp(l->token_tab[0], "tr"))
		;
	else
		add_error(l->d_pars, TOKEN_ER, l->token_tab[0], l->id);
}

int	token_check(t_d_pars *d_pars)
{
	ft_lstiter(d_pars->lst_pars, t_check);
	if (d_pars->nb_cam > 1)
		add_error(d_pars, TOO_MANY_TOKEN_ER, "Camera", 0);
	if (d_pars->nb_cam < 1)
		add_error(d_pars, TOO_FEW_TOKEN_ER, "Camera", 0);
	if (d_pars->nb_amblight > 1)
		add_error(d_pars, TOO_MANY_TOKEN_ER, "Ambiance Light", 0);
	if (d_pars->nb_amblight < 1)
		add_error(d_pars, TOO_FEW_TOKEN_ER, "Ambiance Light", 0);
	print_error(*d_pars);
	if (d_pars->lst_error)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:40:30 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	router_check(void *line)
{
	t_pars_line	*l;

	l = (t_pars_line *)line;
	if (!ft_strcmp(l->token_tab[0], "A"))
		amb_light_check(*l);
	else if (!ft_strcmp(l->token_tab[0], "C"))
		camera_check(*l);
	else if (!ft_strcmp(l->token_tab[0], "L"))
		light_check(*l);
	else if (!ft_strcmp(l->token_tab[0], "sp"))
		sphere_check(*l);
	else if (!ft_strcmp(l->token_tab[0], "pl"))
		plan_check(*l);
	else if (!ft_strcmp(l->token_tab[0], "cy"))
		cylinder_check(*l);
	else if (!ft_strcmp(l->token_tab[0], "tr"))
		triangle_check(*l);
}

int	parser(t_d_pars *d_pars, t_data *data, int fd)
{
	if (parser_init(d_pars, data, fd))
		return (1);
	if (token_check(d_pars))
		return (1);
	ft_lstiter((*d_pars).lst_pars, router_check);
	print_error(*d_pars);
	if ((*d_pars).lst_error)
		return (1);
	return (0);
}

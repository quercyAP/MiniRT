/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:01:57 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	p_parse(void *arg)
{
	t_pars_line	p;

	p = *((t_pars_line *)arg);
	printf("raw line %i : %s\n", p.id, p.raw_line);
	ft_printtab("token_tab", p.token_tab);
}

void	print_parser(t_d_pars d_pars)
{
	ft_lstiter(d_pars.lst_pars, p_parse);
}

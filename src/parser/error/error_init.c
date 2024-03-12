/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:42:06 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	error_init(t_d_pars *d_pars)
{
	d_pars->strerror_tab = ft_calloc(sizeof(char *), ERROR_ENUM_NB);
	d_pars->strerror_tab[TOKEN_ER] = ft_strdup("error unknown token");
	d_pars->strerror_tab[TOO_MANY_TOKEN_ER] = ft_strdup("error too many token");
	d_pars->strerror_tab[TOO_FEW_TOKEN_ER] = ft_strdup("error too few token");
	d_pars->strerror_tab[INVALID_RANGE_ER] = ft_strdup("error invalid range");
	d_pars->strerror_tab[INVALID_FORMAT_ER] = ft_strdup("error invalid format");
	d_pars->strerror_tab[INVALID_LENGTH_ER] = ft_strdup(
			"error invalid parameter length");
	d_pars->strerror_tab[TOO_MANY_PARAM_ER] = ft_strdup(
			"error too many parameter");
	d_pars->strerror_tab[TOO_FEW_PARAM_ER] = ft_strdup(
			"error too few parameter");
	d_pars->strerror_tab[INVALID_NOTDIGIT_ER] = ft_strdup("error not a number");
}

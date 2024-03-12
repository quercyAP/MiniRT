/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_param_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 11:08:46 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	app_param_check(int argc)
{
	if (argc > 2)
	{
		ft_putstr_fd(FT_RED, 2);
		ft_putstr_fd("Too many arguments...\nPlease select only one file.\n", 2);
		ft_putstr_fd(FT_CLEAR, 2);
		return (1);
	}
	if (argc < 2)
	{
		ft_putstr_fd(FT_RED, 2);
		ft_putstr_fd("No argument were given...\nPlease select a file.\n", 2);
		ft_putstr_fd(FT_CLEAR, 2);
		return (1);
	}
	return (0);
}

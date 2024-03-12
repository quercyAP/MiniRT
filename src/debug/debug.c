/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:00:59 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	debug(t_d_pars d_pars, t_data data)
{
	print_parser(d_pars);
	print_cam(data.camera);
	printf("\n");
	print_amb_light(data.amb_light);
	printf("\n");
	ft_lstiter(data.lst_light, print_light);
	printf("\n");
	ft_lstmixtiter(data.lst_object, print_object);
}

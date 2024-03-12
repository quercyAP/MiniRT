/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 09:47:24 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 15:41:57 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data		d;
	t_d_pars	d_pars;

	if (app_param_check(argc))
		return (EXIT_FAILURE);
	if (file_check(argv[1]))
		return (EXIT_FAILURE);
	if (parser(&d_pars, &d, open(argv[1], O_RDONLY)))
	{
		free_d_pars(&d_pars);
		return (EXIT_FAILURE);
	}
	init(d_pars, &d);
	debug(d_pars, d);
	free_d_pars(&d_pars);
	draw(&d);
	mlx_key_hook(d.mlx, key_hook, &d);
	mlx_loop(d.mlx);
	mlx_terminate(d.mlx);
	free_data(&d);
	return (EXIT_SUCCESS);
}

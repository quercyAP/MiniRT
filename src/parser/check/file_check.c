/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 11:09:12 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	file_check(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd(FT_RED, 2);
		ft_putstr_fd("error opening file : ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(FT_CLEAR, 2);
		return (1);
	}
	if (!ft_strnstr(file, ".rt", ft_strlen(file)))
	{
		ft_putstr_fd(FT_RED, 2);
		ft_putstr_fd("error invalid file type (.rt): ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(FT_CLEAR, 2);
		return (1);
	}
	return (0);
}

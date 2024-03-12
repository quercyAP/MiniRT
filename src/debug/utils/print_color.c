/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:02:45 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_color(t_color color, char *str)
{
	if (str)
		printf(" Color %s :\t%s%i %s%i %s%i %s%i\n", str, FT_RED, color.abgr.r,
			FT_GREEN, color.abgr.g, FT_CYAN, color.abgr.b,
			FT_CLEAR, color.abgr.a);
	else
		printf(" Color :\t%s%i %s%i %s%i %s%i\n", FT_RED, color.abgr.r,
			FT_GREEN, color.abgr.g, FT_CYAN, color.abgr.b,
			FT_CLEAR, color.abgr.a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/04/28 15:12:27 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	pixel_tab_clear(t_color **pix_tab)
{
	int	i;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		free(pix_tab[i]);
		i++;
	}
	free(pix_tab);
}

static void	clear_content(void *content)
{
	free(content);
}

void	free_data(t_data *data)
{
	ft_lstclear(&(data->lst_light), clear_content);
	ft_lstmixtclear(&(data->lst_object), clear_content);
	pixel_tab_clear(data->all_pixel);
	pixel_tab_clear(data->bg);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 14:42:45 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	filler(t_pars_line *tmp, char *line, int *count, t_d_pars *d_pars)
{
	tmp->raw_line = line;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	tmp->token_tab = splitter(line);
	tmp->id = (*count)++;
	tmp->d_pars = d_pars;
}

static t_list	*make_list(int fd, t_d_pars *d_pars, t_list *lst_line)
{
	char		*raw_line;
	t_pars_line	*pars_line;
	int			count;

	count = 1;
	while (42)
	{
		raw_line = get_next_line(fd);
		if (!raw_line)
			break ;
		if (raw_line[0] == '\n')
		{
			free(raw_line);
			continue ;
		}
		pars_line = ft_calloc(sizeof(t_pars_line), 1);
		if (!pars_line)
			return (NULL);
		filler(pars_line, raw_line, &count, d_pars);
		ft_lstadd_back(&lst_line, ft_lstnew(pars_line));
	}
	return (lst_line);
}

int	parser_init(t_d_pars *d_pars, t_data *data, int fd)
{
	d_pars->lst_error = NULL;
	error_init(d_pars);
	d_pars->nb_amblight = 0;
	d_pars->nb_cam = 0;
	d_pars->lst_pars = make_list(fd, d_pars, NULL);
	if (!d_pars->lst_pars)
	{
		ft_putstr_fd(FT_RED, 2);
		ft_putstr_fd("Error : file empty\n", 2);
		ft_putstr_fd(FT_CLEAR, 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

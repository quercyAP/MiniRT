/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 08:45:59 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 15:58:00 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_ERROR_H
# define ADD_ERROR_H

int	add_error(t_d_pars *d_pars, enum e_pars_error error, char *arg,
		int line_nb);

#endif

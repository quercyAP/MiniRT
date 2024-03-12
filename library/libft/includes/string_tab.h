/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tab.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:35:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/19 13:22:15 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_TAB_H
# define STRING_TAB_H

char	**ft_split(char const *s, char c);
char	**ft_strtab_dup(char **str_tab);
int		ft_strtab_len(char **str_tab);
void	ft_strtab_clear(char **str_tab);
char	**ft_new_strtab(int size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:35:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/19 13:29:10 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_putchar_pf(char c, int *count);
int		ft_putnbr_pf(int n, int *count);
int		ft_putnbrb_pf(unsigned int n, int *count);
int		ft_putnbrbcap_pf(unsigned int n, int *count);
int		ft_putstr_pf(char *s, int *count);
int		ft_putullnbrb_pf(unsigned long long n, int *count);
int		ft_putunbr_pf(unsigned int n, int *count);
/*
@brief Print the char tab to stdout
@param label the name of the tab to display
@param char_tab the char_tab to print
*/
void	ft_printtab(char *label, char **char_tab);
/*
@brief Print the string list to stdout
@param label the name of the list to display
@param list the list to print
*/
void	ft_printlist_str(char *label, t_list *list);
#endif

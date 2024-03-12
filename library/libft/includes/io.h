/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:35:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 22:01:52 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

/*
@brief Write a char to a file descriptor
@param c the char to write
@param fd the file descriptor
*/
void	ft_putchar_fd(char c, int fd);
/*
@brief Write a string to a file descriptor and put a newline
@param s the string to write
@param fd the file descriptor
*/
void	ft_putendl_fd(char *s, int fd);
/*
@brief Write a number to a file descriptor
@param n the number to write
@param fd the file descriptor
*/
void	ft_putnbr_fd(int n, int fd);
/*
@brief Write a string to a file descriptor
@param s the string to write
@param fd the file descriptor
*/
void	ft_putstr_fd(char *s, int fd);
/*
@brief Read a line from the file descriptor
@param fd the file descriptor
@return Return the line as a string or NULL if fd has reach EOF
*/
char	*get_next_line(int fd);

#endif

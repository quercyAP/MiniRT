/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:35:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 21:54:19 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

/*
@brief Test if the character is alphanumeric
@param c the character to test
@return Return 1 if the character is alphanumeric, 0 if it is not
*/
int	ft_isalnum(int c);
/*
@brief Test if the character is alphabetic
@param c the character to test
@return Return 1 if the character is alphabetic, 0 if it is not
*/
int	ft_isalpha(int c);
/*
@brief Test if the character is ASCII
@param c the character to test
@return Return 1 if the character is ASCII, 0 if it is not
*/
int	ft_isascii(int c);
/*
@brief Test if the character is numeric
@param c the character to test
@return Return 1 if the character is numeric, 0 if it is not
*/
int	ft_isdigit(int c);
/*
@brief Test if the character is printable
@param c the character to test
@return Return 1 if the character is printable, 0 if it is not
*/
int	ft_isprint(int c);
/*
@brief Convert the character to lowercase
@param c the character to convert
@return Return the character in lowercase
*/
int	ft_tolower(int c);
/*
@brief Convert the character to uppercase
@param c the character to convert
@return Return the character in uppercase
*/
int	ft_toupper(int c);

#endif

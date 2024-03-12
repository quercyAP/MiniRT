/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:35:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/03/18 22:40:48 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
/*
@brief Fill n x ZERO at the address given by the pointer s 
@param s the pointer 
@param n the amount of ZERO to fill at the pointer
*/
void	ft_bzero(void *s, size_t n);
/*
@brief Allocate memory and initialize it with ZERO
@param count the amount of item
@param size the size of an item in byte
@return Return a void pointer to the memory allocated
*/
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
/*
@brief Fill n byte(s) c at the address given by the pointer s 
@param s the pointer 
@param c the byte to set
@param len the amount of c to fill at the pointer
*/
void	*ft_memset(void *b, int c, size_t len);

#endif

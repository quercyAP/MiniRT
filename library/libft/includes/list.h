/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdechand <tdechand@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:35:45 by tdechand          #+#    #+#             */
/*   Updated: 2023/05/02 16:02:11 by tdechand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct s_list_mixt
{
	void				*content;
	int					type;
	struct s_list_mixt	*next;
	struct s_list_mixt	*prev;
}					t_list_mixt;

/*
@brief Add the new node to the end of the list
@param lst the list
@param new the node to add
*/
void		ft_lstadd_back(t_list **lst, t_list *new);
/*
@brief Add the new node to the end of the list
@param lst the list
@param new the node to add
*/
void		ft_lstmixtadd_back(t_list_mixt **lst, t_list_mixt *new);
/*
@brief Add the new node to the beginning of the list
@param lst the list
@param new the node to add
*/
void		ft_lstadd_front(t_list **lst, t_list *new);
/*
@brief Clear the list but not the content
@param lst the list
*/
void		ft_lstclear_nc(t_list **lst);
/*
@brief Clear the list and the content with the function given
@param lst the list
@param del the function to clear the content of the list
*/
void		ft_lstclear(t_list **lst, void (*del)(void*));
/*
@brief Clear the list and the content with the function given
@param lst the list
@param del the function to clear the content of the list
*/
void		ft_lstmixtclear(t_list_mixt **lst, void (*del)(void*));
/*
@brief Delete the node and the content with the function given
@param lst the node to delete
@param del the function to clear the content of the node
*/
void		ft_lstdelone(t_list *lst, void (*del)(void*));
/*
@brief Delete the node and the content with the function given
@param lst the node to delete
@param del the function to clear the content of the node
*/
void		ft_lstmixtdelone(t_list_mixt *lst, void (*del)(void*));
/*
@brief Iter the list and apply the function given to the content
@param lst the list to iter
@param f the function to apply
*/
void		ft_lstiter(t_list *lst, void (*f)(void *));
/*
@brief Iter the list and apply the function given to the content
@param lst the list to iter
@param f the function to apply
*/
void		ft_lstmixtiter(t_list_mixt *lst, void (*f)(void *, int));
/*
@brief Iter the list and apply the function given to the content
@param lst the list to iter
@param f the function to apply
@param param the param to give to the function
*/
void		ft_lstiter_param(t_list *lst, void (*f)(void *, void *),
				void *param);
/*
@brief Return the last node of the list
@param lst the list
@return Return the last node or NULL if lst is NULL
*/
t_list		*ft_lstlast(t_list *lst);
/*
@brief Return the last node of the list
@param lst the list
@return Return the last node or NULL if lst is NULL
*/
t_list_mixt	*ft_lstmixtlast(t_list_mixt *lst);
/*
@brief Make a copy of the list and apply the function given to the content
@param lst the list
@param f the function to apply to the new list
@param del the function to clear the content of the new list if it fails
@return Return the new list or NULL if it fails
*/
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/*
@brief Make a new node and set his content
@param content the content
@return Return the new node or NULL if it fails
*/
t_list		*ft_lstnew(void *content);
/*
@brief Make a new node and set his content and type
@param content the content
@param type the type of the content
@return Return the new node or NULL if it fails
*/
t_list_mixt	*ft_lstmixtnew(void *content, int type);
/*
@brief Return the number of node that the list contains
@param lst the list
@return Return the number of node
*/
int			ft_lstsize(t_list *lst);
/*
@brief Return the first node of the list
@param lst the list
@return Return the first node or NULL if lst is NULL
*/
t_list		*ft_lstfirst(t_list *lst);
/*
@brief Iter the list from the end to the beginning
@brief and apply the function given to the content
@param lst the list to iter
@param f the function to apply
*/
void		ft_lstiter_rev(t_list *lst, void (*f)(void *));
/*
@brief Iter the list and apply the function given to the content
@brief and pass it the pointer to current node
@param lst the list to iter
@param f the function to apply
*/
void		ft_lstiter_ref(t_list *lst, void (*f)(void *, t_list *));
/*
@brief Iter the list from the end to the beginning 
@brief and apply the function given to the content
@brief and pass it the pointer to current node
@param lst the list to iter
@param f the function to apply
*/
void		ft_lstiter_rev_ref(t_list *lst, void (*f)(void *, t_list *));
/*
@brief Find the node if the given function return is != 0
@param lst the list to find in
@param param the param to give to the function
@param f the function providing the find pattern 
f(node content, current node, param)
@return Return the first node found
*/
t_list		*ft_lstfind_ref(t_list *lst, void *param,
				int (*f)(void *, t_list *, void *));

#endif

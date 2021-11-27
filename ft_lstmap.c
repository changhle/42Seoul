/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:16:45 by changhle          #+#    #+#             */
/*   Updated: 2021/11/26 19:02:51 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (lst);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	while (*lst)
	{
		ft_lstclear(&(*lst)->next, del);
		del((*lst)->content);
		free(*lst);
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f;
	t_list	*curr;

	lst_f = ft_lstnew(f(lst->content));
	if (lst_f == NULL)
		return (lst_f);
	curr = lst_f;
	while (lst->next != NULL)
	{
		curr->next = ft_lstnew(f(lst->next->content));
		if (curr->next == NULL)
		{
			ft_lstclear(&lst_f, del);
			return (curr->next);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (lst_f);
}

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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f;
	t_list	*curr;

	if (!lst)
		return (NULL);
	lst_f = ft_lstnew(f(lst->content));
	if (!lst_f)
		return (lst_f);
	curr = lst_f;
	while (lst->next)
	{
		curr->next = ft_lstnew(f(lst->next->content));
		if (!curr->next)
		{
			ft_lstclear(&lst_f, del);
			return (curr->next);
		}
		curr = curr->next;
		lst = lst->next;
	}
	return (lst_f);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:16:45 by changhle          #+#    #+#             */
/*   Updated: 2021/11/23 22:16:45 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_cpy;

	lst_cpy = malloc(sizeof(t_list));
	if (!lst_cpy)
		return (NULL);
	while (lst != NULL)
	{
		lst_cpy->content = f(lst->content);
		ft_lstmap(lst->next, f, del);
	}
}

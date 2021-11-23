/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:14:18 by changhle          #+#    #+#             */
/*   Updated: 2021/11/23 17:14:18 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.c>

t_list  *ft_lstnew(void *content)
{
    t_list  *list = malloc(sizeof(t_list));

    list->*content = *content;
    list->next = NULL;
    return (list);
}
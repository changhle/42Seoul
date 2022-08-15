/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 19:42:51 by changhle          #+#    #+#             */
/*   Updated: 2022/08/15 19:42:54 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/libft.h"

void	print_error(char *str)
{
}

char	*delete_newline(char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str[str_len - 1] == '\n')
		str[str_len - 1] = '\0';
	return (str);
}

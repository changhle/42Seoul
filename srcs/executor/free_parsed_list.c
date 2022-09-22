// #include "minishell.h"
// #include "executor.h"
// #include "libft.h"

// static void	free_redirect_list(t_redirect_list *redirect_list)
// {
// 	t_redirect_list *tmp;

// 	while (redirect_list)
// 	{
// 		tmp = NULL;
// 		if (redirect_list->next)
// 			tmp = redirect_list->next;
// 		ft_free((void **)&redirect_list->filename);
// 		ft_free((void **)&redirect_list);
// 		redirect_list = tmp;
// 	}
// }

// static void	free_parsed_unit(t_parsed_unit *parsed_unit)
// {
// 	int	i;

// 	if (!parsed_unit)
// 		return ;
// 	i = 0;
// 	while (parsed_unit->cmd[i])
// 		ft_free((void **)&parsed_unit->cmd[i++]);
// 	ft_free((void **)&parsed_unit->cmd);
// 	if (parsed_unit->redir_in_list)
// 		free_redirect_list(parsed_unit->redir_in_list);
// 	if (parsed_unit->redir_out_list)
// 		free_redirect_list(parsed_unit->redir_out_list);
// 	parsed_unit->redir_in_list = NULL;
// 	parsed_unit->redir_out_list = NULL;
// }

// void	free_parsed_list(t_parsed_list **parsed_list)
// {
// 	t_parsed_list	*tmp;

// 	while (*parsed_list)
// 	{
// 		tmp = NULL;
// 		if ((*parsed_list)->next)
// 			tmp = (*parsed_list)->next;
// 		free_parsed_unit((*parsed_list)->parsed_unit);
// 		(*parsed_list)->parsed_unit = NULL;
// 		ft_free((void **)parsed_list);
// 		*parsed_list = tmp;
// 	}
// }

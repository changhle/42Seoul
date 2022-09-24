#include "minishell.h"
#include "executor.h"
#include "libft.h"

int	execute(t_parsed_list *parsed_list, char **envp)
{
	int				ret_value;
	t_parsed_list	*head;
	t_bool			is_last_cmd;

	ret_value = 0; ///////////// temp
	head = parsed_list;
	ret_value = check_cmd_valid(parsed_list, envp);
	if (ret_value != SUCCESS)
	{
		ft_putstr_fd("Error: command not exists\n", 1); ///////////// temp
		free_parsed_list(&head); ///////////// temp
		return (ret_value);
	}
	is_last_cmd = FALSE;
	(void)is_last_cmd; //////////////temp
	while (parsed_list)
	{
		if (!parsed_list->next)
			is_last_cmd = TRUE;
		// ret_value = exec_command(parsed_list->parsed_unit, envp, is_last_cmd);
		// if (ret_value != SUCCESS)
		// 	break ;
		parsed_list = parsed_list->next;
	}
	free_parsed_list(&head);
	return (ret_value);
}

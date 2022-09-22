#include "minishell.h"
#include "executor.h"

int	exec_command(t_parsed_list *parsed_list, char **envp)
{
	(void)*parsed_list;
	(void)**envp;
	return (0);
}

int	execute(t_parsed_list *parsed_list, char **envp)
{
	int				ret_value;
	t_parsed_list	*head;

	ret_value = 0; ///////////// temp
	head = parsed_list;
	// while (parsed_list && parsed_list->next)
	// {
	// 	ret_value = exec_command(parsed_list, envp);
	// 	parsed_list = parsed_list->next;
	// }
	ret_value = exec_command(parsed_list, envp);
	// free_parsed_list(&head);
	return (ret_value);
}

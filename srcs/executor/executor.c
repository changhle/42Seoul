#include "minishell.h"
#include "executor.h"
#include "libft.h"

#include <sys/wait.h>

static int	wait_child(size_t cmd_cnt, pid_t last_pid)
{
	int		status;
	int		wait_val;
	int		ret;

	while (cmd_cnt--)
	{
		wait_val = wait(&status);
		if (wait_val == -1)
			return (FAILURE);
		if (wait_val == last_pid)
			ret = status;
	}
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	if (WIFSIGNALED(ret))
		return (WTERMSIG(ret) + SIGNAL_EXIT);
	if (WIFSTOPPED(ret))
		return (WSTOPSIG(ret) + SIGNAL_EXIT);
	return (SIG_CONT + SIGNAL_EXIT);
}

static int	invalid_command_return(t_parsed_list **head, char **envp)
{
	free_parsed_list(head);
	ft_free((void **)&envp);
	return (127);
}

int	execute(t_parsed_list *parsed_list, t_env_list **env)
{
	int				ret_value;
	t_context		context;

	init_context(&context, &parsed_list, *env);
	if (check_cmd_valid(parsed_list, *env) != SUCCESS)
		return (invalid_command_return(&context.parsed_head, context.envp));
	while (parsed_list)
	{
		if (!parsed_list->next)
			context.pipe_info.is_last = TRUE;
		ret_value = exec_command_unit(parsed_list->parsed_unit, &context);
		context.pipe_info.is_first = FALSE;
		parsed_list = parsed_list->next;
		context.process_cnt += (ret_value == SUCCESS);
	}
	ret_value = wait_child(context.process_cnt, context.last_pid);
	free_parsed_list(&context.parsed_head);
	ft_free((void **)&context.envp);
	// return (ret_value);
	return (SUCCESS); ///////////// /temp
}

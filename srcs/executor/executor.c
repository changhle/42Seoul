#include "executor.h"
#include "libft.h"

#include <sys/wait.h>
#include <unistd.h>

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
	{
		return (WEXITSTATUS(ret));
	}
	if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGQUIT)
			ft_putstr_fd("Quit: 3", STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		return (WTERMSIG(ret) + SIGNAL_EXIT);
	}
	return (FAILURE);
}

static void	exec_command_unit(
	t_parsed_unit *parsed_unit, t_exec_info *exec_info
	)
{
	if (exec_info->is_first && exec_info->is_last)
		exec_single_cmd(parsed_unit, exec_info);
	else
		exec_multiple_cmd(parsed_unit, exec_info);
}

void	execute(t_parsed_list *parsed_list, t_env_list **env)
{
	t_exec_info		exec_info;

	init_exec_info(&exec_info, &parsed_list, *env);
	while (parsed_list)
	{
		if (!parsed_list->next)
			exec_info.is_last = TRUE;
		exec_command_unit(parsed_list->parsed_unit, &exec_info);
		exec_info.is_first = FALSE;
		parsed_list = parsed_list->next;
	}
	if (exec_info.process_cnt > 0)
		set_exit_status(wait_child(exec_info.process_cnt, exec_info.last_pid));
	free_parsed_list(&exec_info.parsed_head);
	ft_free((void **)&exec_info.envp);
}

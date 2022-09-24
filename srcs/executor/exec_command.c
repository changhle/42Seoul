#include "minishell.h"
#include "executor.h"
#include "libft.h"

// static t_bool	is_builtin(char *command)
// {
// 	return (
// 		ft_iseq(command, "echo")
// 		|| ft_iseq(command, "cd")
// 		|| ft_iseq(command, "pwd")
// 		|| ft_iseq(command, "export")
// 		|| ft_iseq(command, "unset")
// 		|| ft_iseq(command, "env")
// 		|| ft_iseq(command, "exit")
// 	);
// }

// static t_bool	are_all_valid_infile()
// {}

// static int	open_infile(t_redirect_list *redir_in_list)
// {
// 	t_redirect_list	*head;

// 	head = redir_in_list;
// 	if (!are_all_valid_infile(redir_in_list))
// 		return (-1);
// }

// static t_ret_value	get_infd_outfd(
// 	int *infd, int *outfd, t_parsed_unit *parsed_unit
// 	)
// {
// 	infd = open_infile(parsed_unit->redir_in_list);
// 	if (infd == -1)
// 		return (FAILURE);
// }

// int	exec_command(t_parsed_unit *parsed_unit, char **envp, t_bool is_last_cmd)
// {
// 	int	infd;
// 	int	outfd;

// 	if (get_infd_outfd(&infd, &outfd, parsed_unit) != SUCCESS)
// 		return (FAILURE);
// 	(void)*parsed_unit;
// 	(void)**envp; ///////////// temp
// 	return (SUCCESS);
// }

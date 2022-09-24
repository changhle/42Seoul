#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

int		exec_command(t_parsed_unit *parsed_unit, char **envp);
int		exec_last_command(t_parsed_unit *parsed_unit, char **envp);

int		check_cmd_valid(t_parsed_list *parsed_list, char **envp);
void	free_parsed_list(t_parsed_list **parsed_list);

#endif

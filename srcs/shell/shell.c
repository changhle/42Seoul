#include <stdio.h>
#include "readline.h"
#include <unistd.h>
#include <signal.h>
#include <termios.h>

void	sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

char	*read_shell_line(const char *prompt)
{
	char			*line;
	struct termios	new_term;
	struct termios	old_term;

	signal(SIGINT, sig_handler);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDOUT_FILENO, &old_term);
	new_term = old_term;
	new_term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSANOW, &new_term);
	line = readline(prompt);
	tcsetattr(STDOUT_FILENO, TCSANOW, &old_term);
	return (line);
}

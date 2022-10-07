SHELL_DIR		:=	shell
SHELL_SRCS		:=	shell.c shell_banner.c \
					loop_readline.c set_env_list.c
SHELL_SRCS		:=	$(addprefix $(SHELL_DIR)/, $(SHELL_SRCS))

PARSER_DIR		:=	parser
PARSER_SRCS		:=	parser.c tokenizer.c tokenizer_utils.c \
					expander.c expander_utils.c remove_quote.c \
					lexer.c mini_parser.c mini_parser_utils.c \
					word_split.c
PARSER_SRCS		:=	$(addprefix $(PARSER_DIR)/, $(PARSER_SRCS))

EXECUTOR_DIR	:=	executor
EXECUTOR_SRCS	:=	executor.c free_parsed_list.c get_cmd_with_path.c \
					exec_builtin.c \
					init_exec_info.c exec_single_cmd.c exec_multiple_cmd.c \
					get_infile_fd.c get_outfile_fd.c here_doc.c \
					print_minishell_error.c
EXECUTOR_SRCS	:=	$(addprefix $(EXECUTOR_DIR)/, $(EXECUTOR_SRCS))

BUILTIN_DIR		:=	builtin
BUILTIN_SRCS	:=	ft_pwd.c ft_exit.c ft_echo.c ft_cd.c ft_env.c \
					ft_export.c ft_export_utils.c ft_unset.c
BUILTIN_SRCS	:=	$(addprefix $(BUILTIN_DIR)/, $(BUILTIN_SRCS))


SRCS_DIR		:=	srcs
SRCS			:=	main.c \
					$(SHELL_SRCS) \
					$(PARSER_SRCS) \
					$(EXECUTOR_SRCS) \
					$(BUILTIN_SRCS)
SRCS			:=	$(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS			:=	$(SRCS:.c=.o)

INCS_DIR		:=	includes

LIBFT_DIR		:=	libft
LIBFT			:=	$(LIBFT_DIR)/libft.a

READLINE_DIR	:=	readline
READLINE		:=	$(READLINE_DIR)/libreadline.a \
					$(READLINE_DIR)/libhistory.a

CC				:=	gcc
CFLAGS			:=	-g -Wall -Werror -Wextra -D READLINE_LIBRARY
RM				:=	rm -f

NAME			:=	minishell

.PHONY			:	all
all				:	$(NAME)

$(NAME)			:	$(OBJS) $(LIBFT) $(READLINE)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBFT) \
	-L$(READLINE_DIR) -lreadline -lhistory -lncurses

%.o				:	%.c
	$(CC) $(CFLAGS) -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(READLINE_DIR) -c $< -o $@

$(LIBFT)		:
	$(MAKE) -j -C $(LIBFT_DIR) all

$(READLINE)		:
	cd $(READLINE_DIR); ./configure
	$(MAKE) -j -C $(READLINE_DIR) all

.PHONY			:	clean
clean			:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

.PHONY			:	fclean
fclean			:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	#$(MAKE) -C $(READLINE_DIR) clean

.PHONY			:	re
re				:
	make fclean
	make all

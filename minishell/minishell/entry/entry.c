/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:30:48 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:18 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <signal.h>

int	str_to_cmd(char *str, t_cmd **commands, t_env *env, int *exit_s)
{
	int		status;
	t_lex	*lexer;

	lexer = NULL;
	*commands = NULL;
	status = tokenizer(str, &lexer);
	if (status == 0)
		status = parser(commands, &lexer, exit_s);
	if (status == 0)
	{
		status = heredoc(*commands);
		if (status == 1)
		{
			lexer_lstclear(&lexer);
			return (*exit_s = 1, 1);
		}
	}
	if (status == 0)
		status = expansor(*commands, env->env, *exit_s);
	if (status == 0)
		status = expansor_files(*commands, env->env, *exit_s);
	if (status == 1)
		ft_printf_fd(STDERR_FILENO, MSSG_MEMORY_ERROR);
	lexer_lstclear(&lexer);
	return (status);
}

void	generate_terminal(t_env *env)
{
	int		exit_s;
	t_cmd	*cmd;
	char	*str;

	str = readline("minishell$ ");
	exit_s = 0;
	while (str)
	{
		add_history(str);
		if (!quote_check(str))
			printf("minishell: quote error!\n");
		if (str_to_cmd(str, &cmd, env, &exit_s) == 0 && \
		quote_check(str) && cmd != NULL)
		{
			if (execute_commands(cmd, env, &exit_s) == 1)
				ft_printf_fd(STDERR_FILENO, MSSG_EXECUTOR_ERROR);
		}
		parser_lstclear(&cmd);
		free(str);
		str = readline("minishell$ ");
	}
	ft_matrix_free(env->env);
	ft_matrix_free(env->export);
	exit(exit_s);
}

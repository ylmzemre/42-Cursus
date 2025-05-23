/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_syntax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:52:49 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:16 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	parser_error(int error)
{
	ft_printf_fd(STDERR_FILENO, "minishell: ");
	if (error == SYNTAX_NL)
		ft_printf_fd(STDERR_FILENO, MSSG_ERR_NL);
	else if (error == SYNTAX_PIPE)
		ft_printf_fd(STDERR_FILENO, MSSG_ERR_PIPE);
	else if (error == SYNTAX_LESS)
		ft_printf_fd(STDERR_FILENO, MSSG_ERR_LESS);
	else if (error == SYNTAX_LESS_LESS)
		ft_printf_fd(STDERR_FILENO, MSSG_ERR_LESS_LESS);
	else if (error == SYNTAX_GREAT)
		ft_printf_fd(STDERR_FILENO, MSSG_ERR_GREAT);
	else if (error == SYNTAX_GREAT_GREAT)
		ft_printf_fd(STDERR_FILENO, MSSG_ERR_GREAT_GREAT);
}

int	check_duplicate_tokens(t_lex *lexer)
{
	if (lexer->token == LESS || lexer->token == LESS_LESS
		|| lexer->token == GREAT || lexer->token == GREAT_GREAT)
	{
		if (lexer->next == NULL)
		{
			parser_error(SYNTAX_NL);
			return (1);
		}
		else if (lexer->next->token != NONE)
		{
			if (lexer->next->token == PIPE)
				parser_error(SYNTAX_PIPE);
			else if (lexer->next->token == LESS)
				parser_error(SYNTAX_LESS);
			else if (lexer->next->token == LESS_LESS)
				parser_error(SYNTAX_LESS_LESS);
			else if (lexer->next->token == GREAT)
				parser_error(SYNTAX_GREAT);
			else if (lexer->next->token == GREAT_GREAT)
				parser_error(SYNTAX_GREAT_GREAT);
			return (1);
		}
	}
	return (0);
}

int	pipe_error_checker(t_lex *lexer)
{
	if (lexer->token == PIPE)
	{
		if (lexer->prev == NULL)
		{
			parser_error(SYNTAX_PIPE);
			return (1);
		}
		if (lexer->next && lexer->next->token == PIPE)
		{
			parser_error(SYNTAX_PIPE);
			return (1);
		}
		else if (!lexer->next)
		{
			parser_error(SYNTAX_NL);
			return (1);
		}
	}
	return (0);
}

int	check_syntax_error(t_lex *lexer, int *exit_s)
{
	while (lexer)
	{
		if (lexer->token != NONE)
		{
			if (check_duplicate_tokens(lexer) == 1
				|| pipe_error_checker(lexer) == 1)
			{
				*exit_s = 2;
				return (SYNTAX_ERR);
			}
		}
		lexer = lexer->next;
	}
	return (0);
}

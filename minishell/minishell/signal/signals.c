/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:03:52 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:16 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <signal.h>

static void	sig_handler_def(int signum)
{
	if (g_signal == 10)
	{
		if (signum == CTRL_C)
		{
			ft_printf("\n");
			exit(1);
		}
	}
	else if (!g_signal && signum == CTRL_C)
	{
		rl_replace_line("", 1);
		ft_printf("\n");
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == CTRL_SLASH)
		;
}

int	init_signals(void)
{
	signal(CTRL_C, sig_handler_def);
	signal(CTRL_SLASH, sig_handler_def);
	return (1);
}

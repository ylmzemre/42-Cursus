/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansor_utils_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:18:22 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:18 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>

int	ft_change_redirection(t_io *redirect, char *str)
{
	free(redirect->file);
	redirect->file = ft_strdup(str);
	if (!redirect->file)
		return (1);
	free(str);
	str = NULL;
	return (0);
}

int	expand_redirections(t_io *redir, char **env, int ex_s)
{
	char	*str;

	while (redir)
	{
		if (redir->file != NULL)
		{
			str = malloc(sizeof(char) * (calc_len_expan \
			(redir->file, env, ex_s) + 1));
			if (!str)
				return (1);
			ft_memset(str, '\0', calc_len_expan(redir->file, env, ex_s) + 1);
			check_expand(redir->file, ex_s, str, env);
			if (ft_change_redirection(redir, str) == 1)
				return (1);
			redir = redir->next;
		}
		else
			redir = redir->next;
	}
	return (0);
}

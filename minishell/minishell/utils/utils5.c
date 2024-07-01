/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:19:32 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:16 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../inc/minishell.h"

int	quote_len1(char *data)
{
	int	j;
	int	i;
	int	a;

	i = 0;
	j = 0;
	while (data[i])
	{
		if (data[i] == '\"' || data[i] == '\'')
		{
			j++;
			a = data[i++];
			while (data[i] && data[i] != a)
			{
				i++;
			}
			if (!data[i])
				break ;
			j++;
		}
		i++;
	}
	return (j);
}

int	quote_check(char *data)
{
	int	x;

	x = 0;
	x = quote_len1(data);
	if (x % 2 != 0)
		return (0);
	return (1);
}

int	ignore_quote(char const *cmd, int i)
{
	char	quote;

	if (cmd[i] == '\"' || cmd[i] == '\'')
	{
		quote = cmd[i];
		i++;
		while (cmd[i] != '\0' && cmd[i] != quote)
			i++;
		return (i + 1);
	}
	return (i + 1);
}

int	ft_strcmp_env2(char *env, char *str)
{
	int	i;

	i = 0;
	while (env[i] != '=' && str[i] != '\0')
	{
		if (env[i] == '\0' && str[i])
			return (0);
		if (env[i] != str[i])
			return (env[i] - str[i]);
		i++;
	}
	if (env[i] == '=' && str[i] == '\0')
		return (0);
	return (env[i] - str[i]);
}

int	ft_only_dollar(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i] == '$')
			i++;
		else
			i++;
	}
	return (i);
}

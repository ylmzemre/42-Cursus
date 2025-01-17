/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:16:56 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:17 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>

void	ft_matrix_free(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	ft_strcmp_env(char *env, char *str)
{
	int	i;

	i = 0;
	while (env[i] != '=' && str[i] != '\0' && env[i] != '\0')
	{
		if (env[i] == '\0' && str[i])
			return (0);
		if (env[i] != str[i])
			return (env[i] - str[i]);
		i++;
	}
	if ((str[i] == '\0' && env[i] == '=') || (env[i] == '\0' && str[i] == '='))
		return (0);
	return (env[i] - str[i]);
}

char	**ft_free_matrix(char **matrix, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)matrix[j]);
	}
	free(matrix);
	return (NULL);
}

char	*ft_strdup_export(char *envp)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(envp) + 3));
	if (!dup)
		return (NULL);
	while (envp[i] != '=' && envp[i] != '\0')
	{
		dup[i] = envp[i];
		i++;
	}
	if (envp[i] == '=')
	{
		dup[i] = envp[i];
		dup[++i] = C_TWO_QUOTE;
		while (envp[i] != '\0')
			(1 && (dup[i + 1] = envp[i]) && i++);
		dup[i + 1] = C_TWO_QUOTE;
		dup[i + 2] = '\0';
	}
	else
		dup[i] = '\0';
	return (dup);
}

int	ft_strcmp_nocase(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return (ft_tolower(s1[i]) - ft_tolower(s2[i]));
}

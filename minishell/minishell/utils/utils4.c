/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:30:53 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:17 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>

t_env	*generate_env(char **envp)
{
	t_env	*dup;

	dup = malloc(sizeof(t_env));
	if (!dup)
		return (NULL);
	dup->env = malloc((ft_array_len(envp) + 1) * sizeof(char *));
	if (!dup->env)
		return (free(dup), NULL);
	dup->export = malloc((ft_array_len(envp) + 1) * sizeof(char *));
	if (!dup->export)
		return (free(dup->env), free(dup), NULL);
	return (dup);
}

t_env	*ft_get_env(char **envp)
{
	t_env	*dup;
	int		i;

	i = 0;
	dup = generate_env(envp);
	while (envp[i])
	{
		dup->env[i] = ft_strdup(envp[i]);
		if (!dup->env[i])
			return (ft_free_matrix(dup->env, i), free(dup), NULL);
		dup->export[i] = ft_strdup_export(dup->env[i]);
		if (!dup->export[i])
			return (ft_free_matrix(dup->env, i), ft_free_matrix(dup->export, i),
				free(dup), NULL);
		i++;
	}
	return (dup);
}

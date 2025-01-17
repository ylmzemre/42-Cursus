/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:18:51 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:18 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <sys/stat.h>
#include <stdlib.h>

int	directory_errors(char *cmd)
{
	int			i;
	struct stat	file_info;

	file_info.st_mode = 0;
	lstat(cmd, &file_info);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/' && !S_ISREG(file_info.st_mode))
		{
			if (access(cmd, F_OK) == 0)
				return (IS_A_DIR);
			return (NO_SUCH_FILE);
		}
		i++;
	}
	if (S_ISDIR(file_info.st_mode))
		return (CMD_NOT_FOUND);
	return (0);
}

int	try_paths(char **full_path, char *cmd, char **path)
{
	char	*temp;
	int		i;

	i = -1;
	while (full_path[++i])
	{
		temp = ft_strjoin(full_path[i], "/");
		if (!temp)
			return (1);
		*path = ft_strjoin(temp, cmd);
		free(temp);
		if (!*path)
			return (1);
		if (access(*path, F_OK) == 0)
		{
			if (access(*path, X_OK) == 0)
				return (0);
			else
				return (CMD_NO_ACCESS);
		}
		free(*path);
	}
	return (CMD_NOT_FOUND);
}

int	try_local_path(char *cmd, char **path)
{
	char	*temp;
	char	*temp2;

	temp = getcwd(NULL, 0);
	if (!temp)
		return (1);
	temp2 = ft_strjoin(temp, "/");
	if (!temp2)
		return (free(temp), 1);
	*path = ft_strjoin(temp2, cmd);
	free(temp);
	free(temp2);
	if (!*path)
		return (1);
	if (access(*path, F_OK) == 0)
	{
		if (access(*path, X_OK) == 0)
			return (0);
		else
			return (CMD_NO_ACCESS);
	}
	free(*path);
	return (CMD_NOT_FOUND);
}

int	try_absolute_path(char *cmd, char **path)
{
	*path = ft_strdup(cmd);
	if (!*path)
		return (1);
	if (access(*path, F_OK) == 0)
	{
		if (access(*path, X_OK) == 0)
			return (0);
		else
			return (CMD_NO_ACCESS);
	}
	return (CMD_NOT_FOUND);
}

int	search_path(char *cmd, char **envp, char **path)
{
	char	**full_path;
	int		i;
	int		exit_status;

	if (!cmd)
		return (free(cmd), CMD_NOT_FOUND);
	exit_status = directory_errors(cmd);
	if (exit_status != 0)
		return (exit_status);
	i = 0;
	while (envp[i] && ft_strcmp_env(envp[i], "PATH") != 0)
		i++;
	exit_status = CMD_NOT_FOUND;
	if (envp[i])
	{
		full_path = ft_split(envp[i] + 5, ':');
		if (!full_path)
			return (1);
		exit_status = try_paths(full_path, cmd, path);
		ft_free_malloc_array(full_path, ft_array_len(full_path));
	}
	exit_status = search_extra_path(cmd, envp[i], path, exit_status);
	return (exit_status);
}

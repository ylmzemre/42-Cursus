/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:19:26 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:18 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>

int	ft_cd(char **commands, char ***env)
{
	if (!commands[1])
		return (ft_chdir(find_home(*env), env));
	else if (!*commands[1])
		return (0);
	else if (ft_strcmp(commands[1], "..") == 0)
		return (ft_chdir("..", env));
	else if (ft_strcmp(commands[1], ".") == 0)
		return (ft_chdir(".", env));
	else if (ft_strcmp(commands[1], "/") == 0)
		return (ft_chdir("/", env));
	else if (ft_strcmp(commands[1], "~") == 0)
		return (ft_chdir(find_home(*env), env));
	else if (ft_strcmp(commands[1], "-") == 0)
		return (do_oldpwd(env));
	return (ft_chdir(commands[1], env));
}

int	ft_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	ft_printf("%s\n", str);
	free(str);
	return (0);
}

int	ft_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int	ft_echo(char **command)
{
	int	i;

	i = 1;
	if (!command[1])
		ft_printf("\n");
	else if (ft_test_options_echo(command, &i))
	{
		ft_print_matrix(command, i);
	}
	else
	{
		ft_print_matrix(command, i);
		ft_printf("\n");
	}
	return (0);
}

int	ft_unset(char **command, t_env *env)
{
	int	i;
	int	j;

	i = 1;
	while (command[i])
	{
		if (valid_command(command[i]))
		{
			ft_printf_fd(2, "minishell: unset: `%s': not a valid identifier\n",
				command[i]);
			return (1);
		}
		j = 0;
		ft_generate_new_env(command, env->env, j, i);
		ft_generate_new_env(command, env->export, j, i);
		i++;
	}
	return (0);
}

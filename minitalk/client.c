/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm <emreyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:02:17 by emreyilm          #+#    #+#             */
/*   Updated: 2023/10/24 15:03:07 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendbit(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Invalid arguments!\n", 20);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (*argv[2])
		ft_sendbit(pid, *(argv[2]++));
	ft_sendbit(pid, '\n');
	return (0);
}

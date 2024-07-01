/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm <emreyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:29:04 by emreyilm          #+#    #+#             */
/*   Updated: 2024/01/06 14:29:05 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_error(t_stack *stack, char **av, int fre)
{
	if (fre == 1)
		free_data(av);
	free (stack->a);
	free (stack->b);
	write (2, "Error\n", 6);
	exit(1);
}

int	ft_ps_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ps_atoi(char *str, t_stack *stack, char **av, int fre)
{
	unsigned int		i;
	int					neg;
	unsigned long int	num;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if ((str[i] == '-' || str[i] == '+') && !(str[++i] >= '0' && str[i] <= '9'))
		ft_error(stack, av, fre);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack, av, fre);
		num = (str[i] - '0') + (num * 10);
		if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
			ft_error(stack, av, fre);
		i++;
	}
	return (num * neg);
}

void	ft_check_repeat(int size, t_stack *stack, char **str, int fre)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (stack->a[i] == stack->a[j])
				ft_error(stack, str, fre);
	}
}

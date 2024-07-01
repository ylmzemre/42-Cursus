/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm <emreyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:29:20 by emreyilm          #+#    #+#             */
/*   Updated: 2024/01/06 14:29:21 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *stack, int len, int operation)
{
	if (operation == 0)
		pb(stack);
	else
		pa(stack);
	return (len - 1);
}

void	ft_sort_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2])
		sa(s);
	if (s->a[0] > s->a[1] && s->a[1] > s->a[2])
	{
		sa(s);
		rra(s);
	}
	if (s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s);
	if (s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s);
		ra(s);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2])
		rra(s);
}

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
		}
	}
}

int	ft_checked_sorted(int *stack_a, int size, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (++i < size)
			if (stack_a[i - 1] > stack_a[i])
				return (0);
		return (1);
	}
	while (++i < size)
		if (stack_a[i - 1] < stack_a[i])
			return (0);
	return (1);
}

void	ft_sort(t_stack *stack, int size)
{
	if (ft_checked_sorted(stack->a, stack->size_a, 0))
		return ;
	if (size == 2)
		sa(stack);
	else if (size == 3)
		ft_sort_three(stack);
	else
		ft_quicksort_a(stack, size, 0);
}

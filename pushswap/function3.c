/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm <emreyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:29:25 by emreyilm          #+#    #+#             */
/*   Updated: 2024/01/06 14:29:26 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small_b(t_stack *s, int len)
{
	if (len == 1)
		pa(s);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s);
		while (len--)
			pa(s);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				sa(s);
			else if (len == 1 || s->b[0] > s->b[1]
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ft_push(s, len, 1);
			else
				sb(s);
		}
	}
}

void	ft_quicksort_3(t_stack *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ft_sort_three(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack);
			else if (len++)
				pa(stack);
		}
	}
}

int	ft_get_middle(int *pivot, int *stack_a, int size)
{
	int	i;
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (1);
	i = -1;
	while (++i < size)
		tmp[i] = stack_a[i];
	ft_sort_int_tmp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (0);
}

void	ft_quicksort_a(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (ft_checked_sorted(stack->a, len, 0) == 1)
		return ;
	items = len;
	if (len <= 3)
		return (ft_quicksort_3(stack, len));
	if (ft_get_middle(&pivot, stack->a, len))
		return ;
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack);
		else if (++count)
			ra(stack);
	}
	while (items / 2 + items % 2 != stack->size_a && count--)
		rra(stack);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0),
		ft_quicksort_b(stack, items / 2, 0));
}

void	ft_quicksort_b(t_stack *stack, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && ft_checked_sorted(stack->b, len, 1) == 1)
		while (len--)
			pa(stack);
	if (len <= 3)
		return (ft_sort_small_b(stack, len));
	items = len;
	if (ft_get_middle(&pivot, stack->b, len))
		return ;
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack);
		else if (++count)
			rb(stack);
	}
	while (items / 2 != stack->size_b && count--)
		rrb(stack);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0),
		ft_quicksort_b(stack, items / 2, 0));
}

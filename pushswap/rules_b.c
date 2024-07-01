/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm <emreyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:30:51 by emreyilm          #+#    #+#             */
/*   Updated: 2024/01/06 14:30:52 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pb(t_stack *stack)
{
	int	index;

	index = stack->size_b++;
	while (--index >= 0)
		stack->b[index + 1] = stack->b[index];
	stack->b[0] = stack->a[0];
	stack->size_a--;
	while (++index < stack->size_a)
		stack->a[index] = stack->a[index + 1];
	write(1, "pb\n", 3);
}

void	sb(t_stack	*stack)
{
	int	tmp;

	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	rb(t_stack	*stack)
{
	int	tmp;
	int	index;

	index = 0;
	tmp = stack->b[index];
	while (++index < stack->size_b)
		stack->b[index - 1] = stack->b[index];
	stack->b[index - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	index;

	index = stack->size_b;
	tmp = stack->b[index - 1];
	while (--index)
		stack->b[index] = stack->b[index - 1];
	stack->b[index] = tmp;
	write(1, "rrb\n", 4);
}

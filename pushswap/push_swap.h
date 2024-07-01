/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm <emreyilm@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:30:28 by emreyilm          #+#    #+#             */
/*   Updated: 2024/01/06 14:37:41 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

void	ft_error(t_stack *stack, char **av, int fre);
int		ft_ps_strlen(char **str);
int		ft_ps_atoi(char *str, t_stack *stack, char **av, int fre);
void	ft_check_repeat(int size, t_stack *stack, char **str,
			int fre);

int		ft_checked_sorted(int *stack_a, int size, int flag);
void	ft_sort(t_stack *stack, int size);
void	ft_sort_three(t_stack *s);
void	ft_sort_int_tmp(int *tmp_stack, int size);

void	ft_quicksort_3(t_stack *stack, int len);
void	ft_sort_small_b(t_stack *s, int len);
int		ft_push(t_stack *stack, int len, int operation);
int		ft_get_middle(int *pivot, int *stack_a, int size);
void	ft_quicksort_a(t_stack *stack, int len, int count);
void	ft_quicksort_b(t_stack *stack, int len, int count);

void	sa(t_stack *stack);
void	rra(t_stack *stack);
void	ra(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	sb(t_stack	*stack);
void	rb(t_stack	*stack);
void	rrb(t_stack *stack);

void	ft_push_swap(char **av, int fre);

void	free_data(char **data);
int		ft_strcmp(char *s1, char *s2);
int		av_control(char **av);
char	**ft_split(char const *s, char c);
char	**ft_no_malloc(char **tab);

#endif

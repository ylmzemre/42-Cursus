/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:15:51 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:16 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>

t_io	*redirect_lstnew(void)
{
	t_io	*node;

	node = malloc(sizeof(t_io));
	if (!node)
		return (NULL);
	node->file = NULL;
	node->type = REDIRECT_NONE;
	node->next = NULL;
	return (node);
}

void	redirect_lstadd_back(t_io **lst, t_io *new)
{
	t_io	*last;

	if ((*lst))
	{
		last = redirect_lstlast(*lst);
		last->next = new;
	}
	else
		(*lst) = new;
}

void	redirect_lstclear(t_io **lst)
{
	t_io	*temp;
	t_io	*aux;

	aux = *lst;
	while (aux)
	{
		temp = aux->next;
		free(aux->file);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}

int	redirect_lstsize(t_io *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_io	*redirect_lstlast(t_io *lst)
{
	t_io	*node;

	if (!lst)
		return (0);
	node = lst;
	while ((node->next))
		node = node->next;
	return (node);
}

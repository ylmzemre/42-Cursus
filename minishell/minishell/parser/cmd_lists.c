/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lists.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:31:14 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:16 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>

t_cmd	*parser_lstnew(void)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->args = NULL;
	node->redirect = NULL;
	return (node);
}

void	parser_lstadd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	if ((*lst))
	{
		last = parser_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else
		(*lst) = new;
}

void	parser_lstclear(t_cmd **lst)
{
	t_cmd			*temp;
	t_cmd			*aux;
	unsigned int	i;

	i = 0;
	aux = *lst;
	while (aux)
	{
		temp = aux->next;
		if (aux->args)
		{
			while (aux->args[i])
				free(aux->args[i++]);
			free(aux->args);
		}
		redirect_lstclear(&aux->redirect);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}

int	parser_lstsize(t_cmd *lst)
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

t_cmd	*parser_lstlast(t_cmd *lst)
{
	t_cmd	*node;

	if (!lst)
		return (0);
	node = lst;
	while ((node->next))
		node = node->next;
	return (node);
}

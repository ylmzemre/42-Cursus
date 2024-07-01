/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:17:47 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:17 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include <stdlib.h>

t_lex	*lexer_lstnew(void)
{
	t_lex	*node;

	node = malloc(sizeof(t_lex));
	if (!node)
		return (NULL);
	node->word = NULL;
	node->token = NONE;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	lexer_lstadd_back(t_lex **lst, t_lex *new)
{
	t_lex	*last;

	if ((*lst))
	{
		last = lexer_lstlast(*lst);
		last->next = new;
		new->prev = last;
	}
	else
		(*lst) = new;
}

void	lexer_lstclear(t_lex **lst)
{
	t_lex	*nxt;
	t_lex	*aux;

	aux = *lst;
	while (aux)
	{
		nxt = aux->next;
		free(aux->word);
		free(aux);
		aux = nxt;
	}
	*lst = NULL;
}

int	lexer_lstsize(t_lex *lst)
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

t_lex	*lexer_lstlast(t_lex *lst)
{
	t_lex	*node;

	if (!lst)
		return (0);
	node = lst;
	while ((node->next))
		node = node->next;
	return (node);
}

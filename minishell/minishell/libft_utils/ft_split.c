/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:21:04 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:18 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_countsplits(char const *s, char c)
{
	int	qtt;
	int	ini;

	qtt = 0;
	ini = 0;
	if (*s == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == c)
			ini = 0;
		else if (ini == 0)
		{
			ini = 1;
			qtt++;
		}
		s++;
	}
	return (qtt);
}

static int	ft_countlenspit(char const *s2, char c, int i)
{
	int	len;

	len = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free_matrix_split(char const **matrix, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)matrix[j]);
	}
	free(matrix);
	return (NULL);
}

static char	**ft_splitall(char const *s, char **res, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		res[j] = (char *)malloc(sizeof(char) * (ft_countlenspit(s, c, i) + 1));
		if (res[j] == NULL)
			return (ft_free_matrix_split((char const **)res, j));
		while (s[i] != '\0' && s[i] != c)
			res[j][k++] = s[i++];
		res[j][k] = '\0';
		j++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		l;

	if (s == NULL)
		return (NULL);
	l = ft_countsplits(s, c);
	res = (char **)malloc(sizeof(char *) * (l + 1));
	if (res == NULL)
		return (NULL);
	return (ft_splitall(s, res, c, l));
}

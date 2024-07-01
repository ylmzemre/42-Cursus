/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osdemirh  <osdemirh@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:19:40 by osdemirh          #+#    #+#             */
/*   Updated: 2024/05/04 16:34:17 by osdemirh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr_line(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}

size_t	ft_len_line(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup_line(char *s1)
{
	int		i;
	char	*var;

	if (!s1)
		return (NULL);
	i = ft_len_line(s1) + 1;
	var = malloc(i * sizeof(char));
	if (!var)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		var[i] = s1[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char	*ft_strjoin_line(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (ft_strdup_line(s2));
	str = malloc(sizeof(char) * ((ft_len_line(s1) + ft_len_line(s2)) + 1));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_len_line(s1) + ft_len_line(s2)] = '\0';
	if (s1)
		free(s1);
	return (str);
}

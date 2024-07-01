/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm <emreyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:02:55 by emreyilm          #+#    #+#             */
/*   Updated: 2023/07/17 03:02:56 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_s1;
	unsigned char	*s2_s2;
	size_t			i;

	i = 0;
	s1_s1 = (unsigned char *)s1;
	s2_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_s1[i] != s2_s2[i])
			return (s1_s1[i] - s2_s2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm  <emreyilm@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:41:48 by emreyilm          #+#    #+#             */
/*   Updated: 2024/01/15 17:00:45 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	check(va_list arglist, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arglist, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(arglist, char *)));
	else if (c == 'p')
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		return (base(va_arg(arglist, unsigned long long int), 'a' - 10) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arglist, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(arglist, int)));
	else if (c == 'x')
		return (base(va_arg(arglist, unsigned int), 'a' - 10));
	else if (c == 'X')
		return (base(va_arg(arglist, unsigned int), 'A' - 10));
	return (write(1, "%", 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	arglist;
	int		len;
	int		i;
	int		tmp;

	va_start(arglist, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			tmp = check(arglist, s[i]);
			if (tmp == -1)
				return (-1);
			len += tmp - 1;
		}
		else if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
		len++;
	}
	va_end(arglist);
	return (len);
}

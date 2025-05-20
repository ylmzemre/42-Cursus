#include "utilities.h"
#include "stdlib.h"

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

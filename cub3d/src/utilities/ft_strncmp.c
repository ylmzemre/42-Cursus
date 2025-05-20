#include "utilities.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	while (0 < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

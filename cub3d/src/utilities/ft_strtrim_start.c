#include "utilities.h"
#include "stdlib.h"

char	*ft_strtrim_start(char *s1, char *set)
{
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_strchr(set, *s1) && *s1 != '\0')
		s1++;
	return (ft_strdup(s1));
}

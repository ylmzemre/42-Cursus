#include "utilities.h"
#include "stdlib.h"

void	free_double_pointer(char **pointer)
{
	int	i;

	if (pointer == NULL)
		return ;
	i = 0;
	while (pointer[i] != NULL)
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
}

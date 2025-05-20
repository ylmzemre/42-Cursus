#include "cub3d.h"
#include <stdio.h>

void	print_error(t_cub3d *cub3d, char *message)
{
	printf("Error!\n%s\n", message);
	free_cub3d(cub3d);
	exit(EXIT_FAILURE);
}

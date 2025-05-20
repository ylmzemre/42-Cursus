#include "cub3d.h"

t_cub3d	*init_cub3d(int argument_count, char *filename)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	if (cub3d == NULL)
		print_error(cub3d, "cub3d malloc error.");
	init_config(cub3d, argument_count, filename);
	init_xpm_files(cub3d);
	init_colors(cub3d);
	init_map(cub3d);
	cub3d->game = NULL;
	return (cub3d);
}

void	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d == NULL)
		return ;
	free_config(cub3d);
	free_game(cub3d);
	free(cub3d);
}

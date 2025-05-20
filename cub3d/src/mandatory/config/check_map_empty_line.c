#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	check_map_empty_line(t_cub3d *cub3d)
{
	t_config	*config;
	char		*line;
	int			i;
	int			fd;

	config = cub3d->config;
	fd = open(config->filename, O_RDONLY);
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	line = NULL;
	i = 1;
	while (i <= config->total_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (is_empty_line(line) && i > config->map->starting_line)
		{
			free(line);
			print_error(cub3d,
				"There can't be empty line on middle of the map or end");
		}
		free(line);
		i++;
	}
	close(fd);
}

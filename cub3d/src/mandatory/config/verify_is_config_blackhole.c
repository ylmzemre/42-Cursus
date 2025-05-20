#include "../cub3d.h"
#include <fcntl.h>
#include <unistd.h>

void	verify_is_config_blackhole(t_cub3d *cub3d)
{
	char	character;
	int		readed_byte;
	int		fd;

	character = '\0';
	readed_byte = 0;
	fd = open(cub3d->config->filename, O_RDONLY);
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	readed_byte = read(fd, &character, 1);
	if (readed_byte == -1)
		print_error(cub3d, "An error occurred while reading the map file.");
	if (readed_byte == 0)
		print_error(cub3d, "Map file must not be empty.");
	close(fd);
}

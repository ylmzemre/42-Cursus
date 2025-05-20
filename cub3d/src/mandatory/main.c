#include "cub3d.h"
#include "../../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = init_cub3d(argc, argv[1]);
	verify_argument(cub3d);
	verify_is_config_blackhole(cub3d);
	set_config_line_count(cub3d);
	set_config_text(cub3d);
	verify_elements(cub3d);
	verify_map(cub3d);
	init_game(cub3d);
	raycasting(cub3d);
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
		cub3d->game->screen->img, 0, 0);
	mlx_hook(cub3d->game->window, ON_DESTROY, 0, destroy_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYDOWN, 1L << 0, keydown_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYUP, 1L << 1, keyup_handler, cub3d);
	mlx_loop_hook(cub3d->game->mlx, loop_handler, cub3d);
	mlx_loop(cub3d->game->mlx);
	return (0);
}

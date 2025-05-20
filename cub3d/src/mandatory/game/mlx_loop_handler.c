#include "../cub3d.h"
#include "../../../mlx/mlx.h"

static int	is_keys_pressed(t_keys keys)
{
	if (keys.w == 1 || keys.s == 1
		|| keys.a == 1 || keys.d == 1
		|| keys.left == 1 || keys.right == 1)
	{
		return (1);
	}
	return (0);
}

static void	player_move(t_cub3d *cub3d)
{
	if (cub3d->game->keys.w == 1)
		player_move_up(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.s == 1)
		player_move_down(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.a == 1)
		player_move_left(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.d == 1)
		player_move_right(cub3d->config->map, cub3d->game->player);
	if (cub3d->game->keys.left == 1)
		player_turn_left(cub3d->game->player);
	if (cub3d->game->keys.right == 1)
		player_turn_right(cub3d->game->player);
}

int	loop_handler(t_cub3d *cub3d)
{
	t_game	*game;

	game = cub3d->game;
	if (is_keys_pressed(game->keys))
	{
		player_move(cub3d);
		raycasting(cub3d);
		mlx_put_image_to_window(game->mlx,
			game->window, game->screen->img, 0, 0);
	}
	return (0);
}

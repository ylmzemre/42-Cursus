#include "../cub3d.h"

float	real_position_setter_x(t_cub3d *cub3d)
{
	t_ray	ray;

	ray.real_position.x = cub3d->game->player->position.x;
	return (ray.real_position.x);
}

float	real_position_setter_y(t_cub3d *cub3d)
{
	t_ray	ray;

	ray.real_position.y = cub3d->game->player->position.y;
	return (ray.real_position.y);
}

void	raycasting(t_cub3d *cub3d)
{
	int		x;
	t_ray	ray;

	ray.real_position.x = real_position_setter_x(cub3d);
	ray.real_position.y = real_position_setter_y(cub3d);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		ray_properties(&ray, cub3d->game->player, x);
		ray_draw_until_hit_wall(&ray, cub3d->config->map);
		ray_wall_properties(&ray, cub3d->game->player);
		ray_texture_properties(&ray);
		ray_fill_screen(&ray, cub3d->game, x);
		x++;
	}
}

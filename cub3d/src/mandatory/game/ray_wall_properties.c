#include "../cub3d.h"
#include "math.h"

void	ray_wall_properties(t_ray *ray, t_player *player)
{
	t_screen	*screen;

	screen = &ray->screen;
	if (ray->hit_wall_side == 'x')
		ray->view_of_wall = ray->side_dist.x - ray->next_hit_dist.x;
	else
		ray->view_of_wall = ray->side_dist.y - ray->next_hit_dist.y;
	screen->wall_height = (long)(SCREEN_HEIGHT / ray->view_of_wall);
	screen->wall_start_point = SCREEN_HEIGHT / 2 - screen->wall_height / 2;
	screen->wall_end_point = SCREEN_HEIGHT / 2 + screen->wall_height / 2;
	if (ray->hit_wall_side == 'x')
		ray->hit_point_wall = player->position.y
			- ray->view_of_wall * ray->direction.y;
	else
		ray->hit_point_wall = player->position.x
			- ray->view_of_wall * ray->direction.x;
	ray->hit_point_wall -= floor(ray->hit_point_wall);
	screen->hit_point_wall_texture = (int)(ray->hit_point_wall * (double)64);
	if ((ray->hit_wall_side == 'x' && ray->direction.x > 0) || (
			ray->hit_wall_side == 'y' && ray->direction.y < 0))
		screen->hit_point_wall_texture = 64
			- screen->hit_point_wall_texture - 1;
}

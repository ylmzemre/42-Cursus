#include "../cub3d.h"

void	player_move_up(t_map *map, t_player *player)
{
	t_vector_double	new_position;

	new_position.y = player->position.y - player->direction.y * MOVE_SPEED;
	new_position.x = player->position.x - player->direction.x * MOVE_SPEED;
	if (map->text[(int)player->position.y][(int)new_position.x] != '1')
		player->position.x -= player->direction.x * MOVE_SPEED;
	if (map->text[(int)new_position.y][(int)player->position.x] != '1')
		player->position.y -= player->direction.y * MOVE_SPEED;
}

void	player_move_down(t_map *map, t_player *player)
{
	t_vector_double	new_position;

	new_position.y = player->position.y + player->direction.y * MOVE_SPEED;
	new_position.x = player->position.x + player->direction.x * MOVE_SPEED;
	if (map->text[(int)player->position.y][(int)new_position.x] != '1')
		player->position.x += player->direction.x * MOVE_SPEED;
	if (map->text[(int)new_position.y][(int)player->position.x] != '1')
		player->position.y += player->direction.y * MOVE_SPEED;
}

void	player_move_left(t_map *map, t_player *player)
{
	t_vector_double	new_position;

	new_position.y = player->position.y + player->camera_plane.y * MOVE_SPEED;
	new_position.x = player->position.x + player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)player->position.y][(int)new_position.x] != '1')
		player->position.x += player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)new_position.y][(int)player->position.x] != '1')
		player->position.y += player->camera_plane.y * MOVE_SPEED;
}

void	player_move_right(t_map *map, t_player *player)
{
	t_vector_double	new_position;

	new_position.y = player->position.y - player->camera_plane.y * MOVE_SPEED;
	new_position.x = player->position.x - player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)player->position.y][(int)new_position.x] != '1')
		player->position.x -= player->camera_plane.x * MOVE_SPEED;
	if (map->text[(int)new_position.y][(int)player->position.x] != '1')
		player->position.y -= player->camera_plane.y * MOVE_SPEED;
}

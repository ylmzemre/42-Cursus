/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emreyilm  <emreyilm@student.42kocael>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:41:48 by emreyilm          #+#    #+#             */
/*   Updated: 2024/01/15 17:00:50 by emreyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "library/minilibx/mlx.h"
#include "library/printf/ft_printf.h"

void	place_player(t_game *data, int width, int height)
{
	mlx_put_image_to_window(data->mlxpointer,
		data->winpointer, data->player, width * UNIT, height * UNIT);
	data->player_x = width;
	data->player_y = height;
}

void	image_control(t_game *data)
{
	if (!data->playerup || !data->playerdown
		|| !data->playerleft || !data->playerright || !data->wall
		|| !data->exit || !data->collectable)
	{
		ft_printf("XPM file not found.!");
		exit_point(data);
	}
}

void	images_in_game(t_game *data)
{
	int	i;
	int	j;

	data->playerdown = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/down.xpm", &i, &j);
	data->playerup = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/up.xpm", &i, &j);
	data->playerright = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/right.xpm", &i, &j);
	data->playerleft = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/left.xpm", &i, &j);
	data->exit = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/portal.xpm", &i, &j);
	data->wall = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/wall.xpm", &i, &j);
	data->collectable = mlx_xpm_file_to_image(data->mlxpointer,
			"textures/food.xpm", &i, &j);
	image_control(data);
}

void	adding_graphics(t_game *data)
{
	int	height;
	int	width;

	height = -1;
	mlx_clear_window(data->mlxpointer, data->winpointer);
	while (++height < data->map_height)
	{
		width = -1;
		while (data->map[height][++width])
		{
			if (data->map[height][width] == '1')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer, data->wall, width * UNIT, height * UNIT);
			if (data->map[height][width] == 'C')
				mlx_put_image_to_window(data->mlxpointer, data->winpointer,
					data->collectable, width * UNIT, height * UNIT);
			if (data->map[height][width] == 'P')
				place_player(data, width, height);
			if (data->map[height][width] == 'E')
				mlx_put_image_to_window(data->mlxpointer,
					data->winpointer,
					data->exit, width * UNIT, height * UNIT);
		}
	}
}

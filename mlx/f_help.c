/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_help.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:36:31 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 08:36:32 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_struct(t_Map *map)
{
	int	img_width;
	int	img_height;

	map->exit = mlx_xpm_file_to_image(map->mlx, "exit0.xpm", &img_width,
			&img_height);
	map->free_space = mlx_xpm_file_to_image(map->mlx, "free_space.xpm",
			&img_width, &img_height);
	map->player = mlx_xpm_file_to_image(map->mlx, "0.xpm", &img_width,
			&img_height);
	map->collection = mlx_xpm_file_to_image(map->mlx, "collect_1.xpm",
			&img_width, &img_height);
	map->wall = mlx_xpm_file_to_image(map->mlx, "wall_1.xpm", &img_width,
			&img_height);
	if (!map->exit || !map->free_space || !map->player || !map->collection
		|| !map->wall)
	{
		ft_putstr("Error: Failed to load one or more images\n");
		key_hook(65307, map);
		exit(1);
	}
}

static void	update_player_position(t_Map *map, int dx, int dy, int *count)
{
	mlx_put_image_to_window(map->mlx, map->win, map->free_space,
		map->player_p[1] * 64, map->player_p[0] * 64);
	map->player_p[1] += dx;
	map->player_p[0] += dy;
	(*count)++;
	mlx_put_image_to_window(map->mlx, map->win, map->player,
		map->player_p[1] * 64, map->player_p[0] * 64);
}

static int	is_valid_move(t_Map *map, int dx, int dy, int collected)
{
	const int	new_x = map->player_p[1] + dx;
	const int	new_y = map->player_p[0] + dy;

	if (new_x < 0 || new_x >= map->x || new_y < 0 || new_y >= map->y)
		return (0);
	if (map->map[new_y][new_x] == '1')
		return (0);
	if (map->map[new_y][new_x] == 'E' && collected != map->collect)
		return (0);
	return (1);
}

static void	handle_movement(t_Map *map, int keycode, int *count, int *collected)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (keycode == 65363 || keycode == 'd' || keycode == 'D')
		dx = 1;
	else if (keycode == 65361 || keycode == 'a' || keycode == 'A')
		dx = -1;
	else if (keycode == 65364 || keycode == 's' || keycode == 'S')
		dy = 1;
	else if (keycode == 65362 || keycode == 'w' || keycode == 'W')
		dy = -1;
	if (dx || dy)
	{
		if (is_valid_move(map, dx, dy, *collected))
			update_player_position(map, dx, dy, count);
	}
}

void	move_player(t_Map *map, int keycode, int *count)
{
	static int	c;

	handle_movement(map, keycode, count, &c);
	if (map->map[map->player_p[0]][map->player_p[1]] == 'C')
	{
		c++;
		map->map[map->player_p[0]][map->player_p[1]] = '0';
	}
	if (map->map[map->player_p[0]][map->player_p[1]] == 'E'
		&& c == map->collect)
	{
		ft_putstr("You win!\n");
		key_hook(65307, map);
	}
}

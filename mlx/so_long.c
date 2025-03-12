/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:51:26 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 11:51:28 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*get_tile_image(t_Map *map, int i, int j)
{
	char	current;
	void	*img;

	current = map->map[i][j];
	img = NULL;
	if (current == '1')
		img = map->wall;
	else if (current == '0')
		img = map->free_space;
	else if (current == 'C')
		img = map->collection;
	else if (current == 'P')
	{
		map->player_p[0] = i;
		map->player_p[1] = j;
		img = map->player;
	}
	else if (current == 'E')
		img = map->exit;
	return (img);
}

static void	place_tile_image(t_Map *map, void *img, int x, int y)
{
	if (!img)
	{
		ft_putstr("Error: Image loading failed\n");
		free_images(map);
		free_map(map);
		exit(1);
	}
	if (mlx_put_image_to_window(map->mlx, map->win, img, x, y) == -1)
	{
		ft_putstr("Error: Failed to put image to window\n");
		free_images(map);
		free_map(map);
		exit(1);
	}
}

void	fill_screen(t_Map *map)
{
	int		i;
	int		j;
	int		x;
	int		y;
	void	*img;

	y = 0;
	i = 0;
	while (i < map->y)
	{
		x = 0;
		j = 0;
		while (j < map->x)
		{
			img = get_tile_image(map, i, j);
			place_tile_image(map, img, x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}

int	key_hook(int keycode, t_Map *map)
{
	static int	count;
	int			temp;

	if (keycode == 65307)
	{
		mlx_destroy_window(map->mlx, map->win);
		free_images(map);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		free_map(map);
		exit(0);
	}
	else
	{
		temp = count;
		move_player(map, keycode, &count);
		if (temp != count)
		{
			ft_putstr("count is :");
			ft_putnbr(count);
			ft_putstr("\n");
		}
	}
	return (0);
}

void	start_game(t_Map *map)
{
	mlx_connection(map);
	fill_struct(map);
	fill_screen(map);
	mlx_hook(map->win, 2, 1, key_hook, map);
	mlx_hook(map->win, 17, 0, close_window, map);
	mlx_loop(map->mlx);
}

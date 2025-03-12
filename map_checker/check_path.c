/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:42:39 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 09:42:41 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_file(t_Map *map, int x, int y, int *flag)
{
	if (y < 0 || y >= map->y || x < 0 || x >= map->x || map->map[y][x] == '1')
		return ;
	if (map->map[y][x] == 'C')
		map->check_c++;
	if (map->map[y][x] == 'E')
	{
		(*flag)++;
		return ;
	}
	map->map[y][x] = '1';
	flood_file(map, x - 1, y, flag);
	flood_file(map, x + 1, y, flag);
	flood_file(map, x, y - 1, flag);
	flood_file(map, x, y + 1, flag);
}

void	starting_pose(int *x, int *y, t_Map *map)
{
	int	flag;

	flag = 0;
	while (*y < map->y)
	{
		*x = 0;
		while (*x < map->x)
		{
			if (map->map[*y][*x] == 'P')
			{
				flag++;
				break ;
			}
			(*x)++;
		}
		if (flag)
			break ;
		(*y)++;
	}
}

static int	get_map_height(char *av)
{
	int		fd;
	int		height;
	char	*str;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		(ft_putstr("Error\nFailed to open file\n"), exit(1));
	height = 0;
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		height++;
		str = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	fill_map_content(t_Map *map, char *av)
{
	int		fd;
	int		height;
	char	*str;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		(free(map->map), ft_putstr("Error\nFile open failed\n"), exit(1));
	height = 0;
	while (height < map->y)
	{
		str = get_next_line(fd);
		map->map[height++] = str;
	}
	str = get_next_line(fd);
	if (str)
		free(str);
	close(fd);
	map->map[height] = NULL;
}

t_Map	fill_map2(char *av)
{
	t_Map	map;
	int		height;

	height = get_map_height(av);
	map.y = height;
	map.map = malloc(sizeof(char *) * (height + 1));
	if (!map.map)
		allocation_fail();
	fill_map_content(&map, av);
	map.x = ft_strlen1(map.map[0]);
	map.check_c = 0;
	return (map);
}

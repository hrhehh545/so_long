/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:31:32 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 05:31:53 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_Map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

static int	get_map_height(char *name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		(ft_putstr("Error\nOpen failed\n"), exit(1));
	height = 0;
	line = get_next_line(fd);
	while (line && ++height)
		(free(line), line = get_next_line(fd));
	close(fd);
	return (height);
}

static t_Map	*create_map_struct(int height)
{
	t_Map	*map;

	map = malloc(sizeof(t_Map));
	if (!map)
		allocation_fail();
	map->y = height;
	map->map = malloc(sizeof(char *) * (height + 1));
	if (!map->map)
		(free(map), allocation_fail());
	return (map);
}

static void	fill_map_content(t_Map *map, char *name)
{
	int		fd;
	int		h;
	char	*line;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		(free_map(map), ft_putstr("Error\nOpen failed\n"), exit(1));
	h = 0;
	while (h < map->y)
	{
		line = get_next_line(fd);
		map->map[h++] = line;
	}
	line = get_next_line(fd);
	if (line)
		free(line);
	close(fd);
	map->map[h] = NULL;
}

t_Map	*fill_map(char *name)
{
	t_Map	*map;
	int		height;

	height = get_map_height(name);
	if (height < 1)
	{
		ft_putstr("Error\nempty map\n");
		exit(1);
	}
	map = create_map_struct(height);
	fill_map_content(map, name);
	map->x = ft_strlen1(map->map[0]);
	return (map);
}

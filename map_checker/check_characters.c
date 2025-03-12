/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:07:35 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 05:17:58 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_valid_chars(t_Map *map);

void	count_required_characters(t_Map *map, int *p, int *e, int *c)
{
	int		x;
	int		y;
	char	current;

	map->free_space_1 = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			current = map->map[y][x];
			if (current == 'P')
				(*p)++;
			else if (current == 'E')
				(*e)++;
			else if (current == 'C')
				(*c)++;
			else if (current == '0')
				map->free_space_1++;
			x++;
		}
		y++;
	}
}

void	validate_character_counts(t_Map *map, int p, int e, int c)
{
	if (!p || !e || !c)
	{
		ft_putstr("Error\nInvalid map characters\n");
		free_map(map);
		exit(1);
	}
	if (p > 1 || e > 1)
	{
		ft_putstr("Error\nInvalid map characters\n");
		free_map(map);
		exit(1);
	}
	map->collect = c;
	check_valid_chars(map);
}

void	check_characters(t_Map *map)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	count_required_characters(map, &p, &e, &c);
	validate_character_counts(map, p, e, c);
}

void	check_valid_chars(t_Map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] != 'P' && map->map[y][x] != 'E'
				&& map->map[y][x] != 'C' && map->map[y][x] != '0'
				&& map->map[y][x] != '1')
			{
				ft_putstr("Error\nInvalid map characters\n");
				free_map(map);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:37:00 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 05:37:01 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	allocation_fail(void);
void	check_extension(char *str);

t_Map	*map_checker(char *map_name)
{
	t_Map	*map;

	check_extension(map_name);
	map = fill_map(map_name);
	if (map->x > 3840 || map->y > 2160)
	{
		ft_putstr("Error\nthe map is too big!!\n");
		free_map(map);
		exit(1);
	}
	check_rectangular(map);
	check_walls(map);
	check_characters(map);
	check_path(map_name, map);
	return (map);
}

void	check_extension(char *str)
{
	char	*str1;
	int		i;
	int		len;
	int		j;

	str1 = ".ber";
	len = ft_strlen(str);
	i = 4;
	j = 0;
	if (len < 5)
	{
		ft_putstr("Error\ninvalid name of the map\n");
		exit(1);
	}
	else
	{
		while (i > 0)
		{
			if (str[len - i--] != str1[j++])
			{
				ft_putstr("Error\ninvalid name of the map\n");
				exit(1);
			}
		}
	}
}

void	allocation_fail(void)
{
	ft_putstr("Error\nallocation faill\n");
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:46:15 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 08:46:17 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	check_rectangular(t_Map *map)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < map->y)
	{
		if ((ft_strlen1(map->map[i]) != map->x || ft_strlen1(map->map[map->y \
			- 1]) != map->x))
		{
			ft_putstr("Error\nthe map not rectangular\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
}

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'));
}

int	close_window(t_Map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	free_images(map);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	exit(0);
	return (0);
}

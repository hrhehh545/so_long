/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f2_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 07:33:39 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 10:03:16 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_connection(t_Map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		ft_putstr("Error\nmlx connection fail\n");
		free_map(map);
		exit(1);
	}
	map->win = mlx_new_window(map->mlx, map->x * 64, map->y * 64, "SO_LONG");
	if (!map->win)
	{
		ft_putstr("Error\nmlx window fail\n");
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		free_map(map);
		exit(1);
	}
}

void	free_images(t_Map *map)
{
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->free_space)
		mlx_destroy_image(map->mlx, map->free_space);
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
	if (map->collection)
		mlx_destroy_image(map->mlx, map->collection);
	if (map->wall)
		mlx_destroy_image(map->mlx, map->wall);
}

void	check_path(char *av, t_Map *map)
{
	t_Map	map2;
	int		x;
	int		y;
	int		i;
	int		flag;

	map2 = fill_map2(av);
	x = 0;
	y = 0;
	i = 0;
	flag = 0;
	starting_pose(&x, &y, map);
	map2.check_c = 0;
	flood_file(&map2, x, y, &flag);
	while (map2.map[i])
		free(map2.map[i++]);
	free(map2.map);
	if (!flag || map2.check_c != map->collect)
	{
		ft_putstr("Error\ninvalid path\n");
		free_map(map);
		exit(1);
	}
}

void	ft_putchar(char c)
{
	write(0, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

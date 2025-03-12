/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:37:33 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 05:37:34 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_Map	*map;

	if (ac != 2)
	{
		ft_putstr("Error\ninvalid argument number\n");
		return (1);
	}
	map = map_checker(av[1]);
	start_game(map);
}

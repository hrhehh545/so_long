/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomoumen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:38:13 by yomoumen          #+#    #+#             */
/*   Updated: 2025/02/22 11:39:23 by yomoumen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct map
{
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	int		check_c;
	int		collect;
	char	**map;
	int		free_space_1;
	int		player_p[2];
	void	*player;
	void	*wall;
	void	*free_space;
	void	*collection;
	void	*exit;
}			t_Map;

t_Map		*map_checker(char *av);
void		ft_putstr(char *str);
void		free_map(t_Map *map);
void		check_rectangular(t_Map *map);
int			ft_strlen1(char *str);
void		check_walls(t_Map *map);
void		check_characters(t_Map *map);
void		check_path(char *av, t_Map *map);
void		allocation_fail(void);
void		start_game(t_Map *map);
void		fill_struct(t_Map *map);
void		move_player(t_Map *map, int keycode, int *count);
void		free_images(t_Map *map);
int			key_hook(int keycode, t_Map *map);
t_Map		*fill_map(char *name);
void		free_map(t_Map *map);
void		mlx_connection(t_Map *map);
void		free_images(t_Map *map);
void		check_path(char *av, t_Map *map);
t_Map		fill_map2(char *av);
void		flood_file(t_Map *map, int x, int y, int *flag);
void		starting_pose(int *x, int *y, t_Map *map);
void		ft_putnbr(int n);
int			ft_isalnum(int c);
int			close_window(t_Map *map);

#endif

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "mlx.h"

typedef struct map{
    int y;
    int x;
    char **map;
} Map;

Map * map_checker(char *av);
void ft_putstr(char *str);
void free_map(Map *map);
void check_rectangular(Map *map);
int ft_strlen1(char *str);
void check_walls(Map *map);
void check_characters(Map *map);
void check_path(char *av, Map *map);
void allocation_fail();
void print_map(Map *map);
//void start_game(Map *map)


#endif
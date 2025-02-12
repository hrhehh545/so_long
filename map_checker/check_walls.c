#include "../so_long.h"

void first_row(Map *map);
void last_row(Map *map);
void middle_rows(Map *map);

void check_walls(Map *map)
{
    first_row(map);
    last_row(map);
    middle_rows(map);
}

void middle_rows(Map *map)
{
    int i = 1;
    while(i < map->y - 2)
    {
        if(map->map[i][0] != '1' || map->map[i][map->x - 1] != '1')
        {
            ft_putstr("Error\nthe map not rounded by walls\n");
            free_map(map);
            exit(1);
        }
        i++;
    }
}

void first_row(Map *map)
{
    int i = 0;
    while(i < map->x)
    {
        if(map->map[0][i] != '1')
        {
            ft_putstr("Error\nthe map not rounded by walls\n");
            free_map(map);
            exit(1);
        }
        i++;
    }
}

void last_row(Map *map)
{
    int i = 0;
    while(i < map->x)
    {
        if(map->map[map->y - 1][i] != '1')
        {
            ft_putstr("Error\nthe map not rounded by walls\n");
            free_map(map);
            exit(1);
        }
        i++;
    }
}
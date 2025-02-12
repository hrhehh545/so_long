#include "../so_long.h"

void check_valid_chars(Map *map);

void check_characters(Map *map)
{
    int x = 0;
    int y = 0;
    int p = 0;
    int e = 0;
    int c = 0;
    int free_space = 0;
    while(y < map->y)
    {
        x = 0;
        while(x < map->x)
        {
            if(map->map[y][x] == '0')
                free_space++;
            else if(map->map[y][x] == 'P')
                p++;
            else if(map->map[y][x] == 'E')
                e++;
            else if(map->map[y][x] == 'C')
                c++;
            x++;
        }
        y++;
    }
    if(!p || !c || !e || !free_space)
    {
        ft_putstr("Error\nInvalid map characters\n");
        free_map(map);
        exit(1);
    }
    if(p > 1 || e > 1)
    {
        ft_putstr("Error\nInvalid map characters\n");
        free_map(map);
        exit(1);
    }
    check_valid_chars(map);
}


void check_valid_chars(Map *map)
{
    int x = 0;
    int y = 0;
    while(y < map->y)
    {
        x = 0;
        while(x < map->x)
        {
            if(map->map[y][x] != 'P' && map->map[y][x] != 'E' && map->map[y][x] != 'C' && map->map[y][x] != '0' && map->map[y][x] != '1')
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
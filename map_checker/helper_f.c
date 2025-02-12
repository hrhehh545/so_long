#include "../so_long.h"


int ft_strlen1(char *str)
{
    int i = 0;
    while(str[i] && str[i] != '\n')
        i++;
    return i;
}

void ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

void check_rectangular(Map *map)
{
    int len = 0;
    int i = 0;
    while(i < map->y)
    {
        if((ft_strlen1(map->map[i]) != map->x || ft_strlen1(map->map[map->y - 1]) != map->x ))
        {
            ft_putstr("Error\nthe map not rectangular\n");
            free_map(map);
            exit(1);
        }
        i++;
    }
}

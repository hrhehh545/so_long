#include "../so_long.h"

Map fill_map2(char *av);

void flood_file(Map map, int x, int y, int *flag)
{
    if(y < 0 || y >= map.y || x < 0 || x >= map.x || map.map[y][x] == '1')
        return;
    if(map.map[y][x] == 'E')
    {
        (*flag)++;
        return;
    }
    map.map[y][x] = '1';
    flood_file(map, x-1, y, flag);
    flood_file(map, x+1, y, flag);
    flood_file(map, x, y-1, flag);
    flood_file(map, x, y+1, flag);
}

void starting_pose(int *x, int *y, Map *map)
{
    int flag = 0;
    while(*y < map->y)
    {
        *x = 0;
        while(*x < map->x)
        {
            if(map->map[*y][*x] == 'P')
            {
                flag++;
                break;
            }
            (*x)++;
        }
        if(flag)
            break;
        (*y)++;
    }
}

void check_path(char *av, Map *map)
{
    Map map2;
    map2 = fill_map2(av);
    int x = 0;
    int y = 0;
    int i = 0;
    starting_pose(&x, &y, map);
    static int flag;
    flood_file(map2, x, y, &flag);
    while(map2.map[i])
        free(map2.map[i++]);
    free(map2.map);
    if(!flag)
    {
        ft_putstr("Error\ninvalid path\n");
        free_map(map);
        exit(1);
    }
}

Map fill_map2(char *av)
{
    int fd = open(av, 0);
    int height = 0;
    char *str;
    Map map;
    while(str = get_next_line(fd))
    {
        free(str);
        height++;
    }
    map.y = height;
    close(fd);
    map.map = malloc(sizeof(char *) * (height + 1));
    if(!map.map)
        allocation_fail();
    height = 0;
    fd = open(av, 0);
    while(height < map.y)
    {
        map.map[height] = get_next_line(fd);
        free(str);
        height++;
    }
    free(get_next_line(fd));
    map.map[height] = NULL;
    int len = ft_strlen1(map.map[0]);
    map.x = len;
    return map;
}

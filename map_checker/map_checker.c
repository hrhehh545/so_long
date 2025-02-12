#include "../so_long.h"

void allocation_fail();
void check_extension(char *str);
Map *fill_map(char *name);
void free_map(Map *map);

Map *map_checker(char *map_name)
{
    check_extension(map_name);
    Map *map;
    map = fill_map(map_name);
    check_rectangular(map);
    check_walls(map);
    check_characters(map);
    check_path(map_name, map);
    return map;
}

Map *fill_map(char *name)
{
    int fd = open(name, 0);
    int height = 0;
    char *str;
    while(str = get_next_line(fd))
    {
        free(str);
        height++;
    }
    Map *map = malloc(sizeof(Map));
    if(!map)
        allocation_fail();
    map->y = height;
    close(fd);
    map->map = malloc(sizeof(char *) * (height + 1));
    if(!map->map)
    {
        free(map);
        allocation_fail();
    }
    height = 0;
    fd = open(name, 0);
    while(height < map->y)
    {
        map->map[height] = get_next_line(fd);
        free(str);
        height++;
    }
    free(get_next_line(fd));
    map->map[height] = NULL;
    int len = ft_strlen1(map->map[0]);
    map->x = len;
    return map;
}

void check_extension(char *str)
{
    int i = 0;
    int j = 0;
    char *str1 = ".ber";
    int flag = 0;
    while(str[i])
    {
        if(str[i] == '.')
        {
            while(str[i] || str1[j])
            {
                if(str[i++] == str1[j++])
                    flag = 1;
                else
                {
                    flag = 0;
                    break;
                }
            }
            break;
        }
        i++;
    }
    if(!flag)
    {
        ft_putstr("Error\ninvalid map extension\n");
        exit(1);
    }
}

void allocation_fail()
{
    ft_putstr("Error\nallocation faill\n");
    exit(1);
}


void free_map(Map *map)
{
    int i = 0;
    while(map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    free(map);
}
/* free map
    int i = 0;
    while(map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    free(map);
*/
#include "so_long.h"

int main(int ac, char *av[])
{
    if(ac != 2)
    {
        ft_putstr("Error\ninvalid argument number");
        return 1;
    }
    Map *map;
    map = map_checker(av[1]);
    print_map(map);
    free_map(map);
}
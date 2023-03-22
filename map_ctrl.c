#include "cub3d.h"

// check if map is enclosed by walls wall = 1

void check_map(t_cube   *info)
{
    int     i;
    int     j;

    i = 0;
    while (i < info->map_height)
    {

        if ( i == 0 || i == info->map_width)
        {
            j = 0;
            while (j++ < info->map_width)
            {
                printf("map[0][%d] = [%c]\n", j, info->map[0][j]);
                if (info->map[0][j] == '0' || info->map[info->map_height - 1][j] == '0')
                    cub3d_error("Map is not closed/surrounded by walls.\n");
            }
            // cub3d_error("Map is not closed/surrounded by walls.\n");
        }
        i++;
    }
    // i = 0;
    // while (i < info->map_width)
    // {
    //     if (info->map[i][0] != '1' || info->map[i][info->map_height - 1] != '1')
    //         cub3d_error("Map is not closed/surrounded by walls.\n");
    //     i++;
    // }
}


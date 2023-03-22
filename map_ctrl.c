#include "cub3d.h"

// check if map is enclosed by walls wall = 1

void edge(char *line)
{
    int j;

    j = -1;
    while (++j < ft_strlen(line))
    {
        if (line[j] == '0')
            cub3d_error("Map is not closed/surrounded by walls.\n");
    }

}

void    sides(char *line)
{
    printf("{%s}",line);
        
}

void check_map(t_cube   *info)
{
    int i;
    int j;
    if (info->map[0][0] && info->map[info->map_height - 1][0])
    {
        edge(&info->map[0][0]);
        edge(&info->map[info->map_height - 1][0]);
    }
    i = -1;
    while (++i < info->map_height && info->map[i][0])
    {
        j = -1; 
        while(++j < info->map_width && info->map[i][j])
        {
            if (info->map[i][j] && info->map[i][j] == '0')
            {
                sides(&info->map[i][0]);
                break;
            }

        }
    }
}


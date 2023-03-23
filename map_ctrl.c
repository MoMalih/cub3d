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

int check_zero(char **map, int h, int w)
{
    int i = 1;
    int j, flag;

    while (i < h - 1)
    {
        j = 1;
        flag = 0;
        while (j < w - 1)
        {
            if (map[i][j] == '0')
            {
                if (map[i - 1][j] == '0' || map[i + 1][j] == '0' || map[i][j - 1] == '0' || map[i][j + 1] == '0')
                    flag = 1;
                else
                    return (0);
            }
            j++;
        }
        if (flag == 0)
            return (0);
        i++;
    }
    return (1);
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
                if(check_zero(info->map, info->map_height, info->map_width) == 0)
                    cub3d_error("Map is not closed by walls.\n");
                break;
            }

        }
    }
}

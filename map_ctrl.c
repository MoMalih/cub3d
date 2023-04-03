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

char	*fs_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i > -1)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

void    search_r(char **map, int h, int w)
{
    while (map[h][++w] == ' ');
    // printf("rr {%c}\n", map[h][w]);

    if (h > 0 && w >= 0 && map[h][w] != '1' && map[h][w] != '\0')
        cub3d_error("Map is not {r} closed/surrounded by walls.\n");
}

void    search_l(char **map, int h, int w)
{
    while (map[h][--w] == ' ' && w >= 0);
    // printf("ll {%c}\n", map[h][w]);
    if (h > 0 && w >= 0 && map[h][w] != '1' && map[h][w] != '\0')
        cub3d_error("Map is not closed/surrounded by walls.\n");
}

void    search_t(char **map, int h, int w)
{
    while (map[--h][w] == ' ' && h > 0);
    // printf("tt {%c}\n", map[h][w]);
    if (h > 0 && w >= 0 && map[h][w] != '1')
        cub3d_error("Map is not closed/surrounded by walls.\n");
}

void    search_d(char **map, int h, int w, int height)
{
    (void)height;
    while (h < height -1 && map[++h][w] == ' ');
    // printf("dd {%c}  w {%d}\n", map[h][w], w);
    // printf("h {%d}\n", h);
    if (h != (height - 1) && w >= 0 && map[h][w] != '1')
        cub3d_error("Map is not closed/surrounded by walls.\n");
}

void    space_check(t_cube  *info, int i)
{
    int it;

    it = -1;
    while(++it < ft_strlen(&info->map[i][0]))
    {
        if (info->map[i][it] == ' ' && i > 0
         && i < info->map_height)
        {
            search_r(info->map, i, it);
            search_l(info->map, i, it);
            search_t(info->map, i, it);
            search_d(info->map, i, it, info->map_height);
        }
    }
}

void inputs(t_cube *info)
{
    int it;
    int it1;
    int flag;

    it = -1;
    flag = 0;
    while(++it < info->map_height)
    {
        it1 = -1;
        while(++it1 <= ft_strlen(&info->map[it][0]) && info->map[it][it1])
        {
            if (info->map[it][it1] == 'N' || info->map[it][it1] == 'E'
                || info->map[it][it1] == 'W' || info->map[it][it1] == 'S')
                flag = 1;
            else
            {
                if (info->map[it][it1] != '0' && info->map[it][it1] != '1' 
                    && info->map[it][it1] != ' ' )
                    cub3d_error("undefined char on map");
            }
        }
    }
    if(!flag)
        cub3d_error("please add a player");
}

void check_map(t_cube   *info)
{
    int i;

    inputs(info);
    if (info->map[0][0] && info->map[info->map_height - 1][0])
    {
        edge(&info->map[0][0]);
        edge(&info->map[info->map_height - 1][0]);
    }
    i = -1;
    while (++i < info->map_height)
    {
        else if (fs_strchr(&info->map[i][0], SPACE))
            space_check(info, i);
        // if (info->map[i][0] != '1' || info->map[i][ft_strlen(&info->map[i][0]) - 1] != '1')
        //     cub3d_error("Map is not surrounded by walls.\n");
        // else
        // {
        // }
    }
}


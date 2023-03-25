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
    if (map[h][w] == '0')
        cub3d_error("Map is not closed/surrounded by walls.\n");
}

void    search_l(char **map, int h, int w)
{
    while (map[h][--w] == ' ' && w >= 0);
    if (map[h][w] == '0')
        cub3d_error("Map is not closed/surrounded by walls.\n");
}

void    search_t(char **map, int h, int w)
{
    while (map[--h][w] == ' ' && h > 0);
    if (map[h][w] == '0')
        cub3d_error("Map is not closed/surrounded by walls.\n");
}

void    search_d(char **map, int h, int w, int height)
{
    (void)height;
    while (h < height -1 && map[++h][w] == ' ');
    if (map[h][w] == '0')
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

void check_map(t_cube   *info)
{
    int i;
    // int j;
    // char    *sp_line;


    if (info->map[0][0] && info->map[info->map_height - 1][0])
    {
        edge(&info->map[0][0]);
        edge(&info->map[info->map_height - 1][0]);
    }
    i = -1;
    while (++i < info->map_height)
    {
        if (fs_strchr(&info->map[i][0], SPACE))
            space_check(info, i);
        // printf("{%c}\n",info->map[i][j]);
        // printf("{%c}\n",info->map[i][ft_strlen(&info->map[i][0]) -2]);
        // j = 0;
        // while(info->map[i][j] == SPACE)
        //     j++;
        // printf("{%s}\n", &info->map[i][j]);
        // printf("{%d}\n", ft_strlen(&info->map[i][j]));
        // if (info->map[i][j] != '1' || info->map[i][ft_strlen(&info->map[i][0])] != '1')
        // {
        //     cub3d_error("Map is not surrounded by walls.\n");
        // }
    }
}


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

void    space_check(t_cube  *info, int h)
{
    int it;

    it = -1;
    while(++it < ft_strlen(&info->map[i][0]))
    {
        if (info->map[i][it] == ' ' && i > 0
         && i < info->map_height -1)
        {
            while (info->map[i][it] == ' ')
        }
    }

}

void check_map(t_cube   *info)
{
    int i;
    int j;
    // char    *sp_line;


    if (info->map[0][0] && info->map[info->map_height - 1][0])
    {
        edge(&info->map[0][0]);
        edge(&info->map[info->map_height - 1][0]);
    }
    i = -1;
    while (++i < info->map_height)
    {
        j = 0;
        // while(info->map[i][j] == SPACE)
        //     j++;
        // printf("{%c}\n",info->map[i][j]);
        // printf("{%c}\n",info->map[i][ft_strlen(&info->map[i][0]) -2]);
        if (fs_strchr(&info->map[i][0], SPACE))
        {
            printf("{%s}\n",&info->map[i][0]);
            // all spaces are surronded by 1
            space_check(info, i)


        }    
        else if (info->map[i][j] != '1' || info->map[i][ft_strlen(&info->map[i][0]) - 1] != '1')
            cub3d_error("Map is not surrounded by walls.\n");
    }
}


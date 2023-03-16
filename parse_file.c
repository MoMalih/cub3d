#include "cub3d.h"

void    parse_texture(char *line, char **texture)
{
    int     i;
    int     j;

    i = 0;
    while (line[i] && line[i] != SPACE)
        i++;
    while (line[i] && line[i] == SPACE)
        i++;
    j = i;
    while (line[j] && line[j] != SPACE)
        j++;
    if (line[j])
        cub3d_error("Invalid file texture");
    *texture = ft_substr(line, i, j - i);
}

int    is_num(char c)
{
    if(c <= '0' && c >= '9')
        return 1;
    return 0;
}

void    parse_color(char *line, int *color)
{
    int     i;
    int     j;
    int     r;
    int     g;
    int     b;

    i = 0;
    while (line[i] && line[i] != SPACE)
        i++;
    while (line[i] && line[i] == SPACE)
        i++;
    j = i;
    while (line[j] && line[j] != ',' && is_num(line[j]))
        j++;
    // printf("i >>>>>>>>>>>>>{%d}\n", i);
    // printf("j >>>>>>>>>>>>>{%d}\n", j);
    if (!line[j])
        cub3d_error("Invalid file co");
    r = ft_atoi(line + i);
    i = j + 1;
    j = i;
    while (line[j] && line[j] != ',' && is_num(line[j]))
        j++;
    if (!line[j])
        cub3d_error("Invalid file lo");
    g = ft_atoi(line + i - 1);

    i = j + 1;
    j = i;
    while (line[j] && line[j] != SPACE && is_num(line[j]))
        j++;
    printf("line : {%s}\n",line);
    b = ft_atoi(line + i);
        // if(line[j] == '\n')
        //     break;
        printf("r >>{%d}\n", r);
        printf("g >>{%d}\n", g);
        printf("b >>{%d}\n", b);
    // if (line[j])
    //     cub3d_error("Invalid file rs");
    *color = (r << 16) | (g << 8) | b;
}

// void    parse_map(t_cube *info, char *line)
// {

// }

void    parse_file(t_cube   *info)
{
    char    *line;
    // int     ret;


    line = get_next_line(info->fd);
    while (line)
    {
        if (ft_strlen(line) > 0 && line[0] != '\n')
        {
            if (line[0] == 'N' && line[1] == 'O')
                parse_texture(line, &info->north);
            else if (line[0] == 'S' && line[1] == 'O')
                parse_texture(line, &info->south);
            else if (line[0] == 'W' && line[1] == 'E')
                parse_texture(line, &info->west);
            else if (line[0] == 'E' && line[1] == 'A')
                parse_texture(line, &info->east);
            else if (line[0] == 'F')
                parse_color(line, &info->floor);
            else if (line[0] == 'C')
                parse_color(line, &info->ceiling);
        }
        else
            free(line);
        line = get_next_line(info->fd);
        // if (line[0] == '1' || line[0] == SPACE)
        //     parse_map(info, line);
    }
    free(line);
    printf("NO {%s}\n", info->north);
    printf("SO {%s}\n", info->south);
    printf("WE {%s}\n", info->west);
    printf("EA {%s}\n", info->east);
    printf("C {%d}\n", info->ceiling);
    printf("F {%d}\n", info->floor);
}
    // if (line == -1)
    //     cub3d_error("Invalid file");
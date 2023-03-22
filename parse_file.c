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

void    parse_color(char *line, int *color)
{
    int     s;
    int     e;
    int     r;
    int     g;
    int     b;

    s = 0;
    while (line[s] && line[s] != SPACE)
        s++;
    while (line[s] && line[s] == SPACE)
        s++;
    // printf("line >> {%s}\n",&line[s]);
    // printf("e >>>>>>>>>>>>>{%d}\n", e);
    e = s;
    while (line[e] && line[e] != ',' && ft_isdigit(line[e]))
        e++;
    if (!line[e])
        cub3d_error("Invalid file co");
    r = ft_atoi(line + s);
    if(r > 255 || r < 0)
        cub3d_error("Invalid RGB PARAMETRE");
    // printf("r >>{%d}\n", r);
    s = e + 1;
    e = s;
    while (line[e] && line[e] != ',' && ft_isdigit(line[e]))
        e++;
    if (!line[e])
        cub3d_error("Invalid file lo");
    g = ft_atoi(line + s);
    if(g > 255 || g < 0)
        cub3d_error("Invalid RGB PARAMETRE");
    // printf("g >>{%d}\n", g);

    s = e + 1;
    e = s;
    while (line[e] && line[e] != SPACE  && ft_isdigit(line[e]))
        e++;
    b = ft_atoi(line + s);
    if(b > 255 || b < 0)
        cub3d_error("Invalid RGB PARAMETRE");
    // printf("b >>{%d}\n", b);
        // if(line[j] == '\n')
        //     break;
    // if (line[j])
    //     cub3d_error("Invalid file rs");
    *color = (r << 16) | (g << 8) | b;
}

void    parse_map(t_cube *info, char *line, int it)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (it == 1)
    {
        info->map_width = ft_strlen(line);
        info->map_height = 1;
        info->map = malloc(sizeof(char *) * info->map_height);
        info->map[0] = malloc(sizeof(char) * info->map_width);
        while (line[i])
        {
            info->map[0][i] = line[i];
            i++;
        }
        // printf("width >> {%d}\n",info->map_width);
    }
    else
    {
        info->map_height++;
        info->map = realloc(info->map, sizeof(char *) * info->map_height);
        info->map[it - 1] = malloc(sizeof(char) * info->map_width);
        while (line[i])
        {
            info->map[it - 1][i] = line[i];
            i++;
        }
    }
}

void    parse_file(t_cube   *info)
{
    char    *line;
    int     it;
    // int     j;

    it = 1;
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
            else if (line[0] == '1' || line[0] == SPACE)
                parse_map(info, line, it++);
        }
        // else
        //     free(line);
        line = get_next_line(info->fd);
    }
    free(line);
    check_map(info);
    // printf("NO {%s}", info->north);
    // printf("SO {%s}", info->south);
    // printf("WE {%s}", info->west);
    // printf("EA {%s}", info->east);
    // printf("C {%d}", info->ceiling);
    // printf("F {%d}", info->floor);
    // printf("height >> {%d}\n",info->map_height);
    // printf("width >> {%d}\n", info->map_width);
    // j = -1;
    // while (++j < info->map_height)
    //     printf("line %d >> %s", j,info->map[j]);
}
    // if (line == -1)
    //     cub3d_error("Invalid file");
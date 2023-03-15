#include "cub3d.h"

void    parse_texture(char *line, char **texture)
{
    int     i;
    int     j;

    i = 0;
    // if(!info->fd)
    //     cub3d_error("Invalid file");
    while (line[i] && line[i] != ' ')
        i++;
    while (line[i] && line[i] == ' ')
        i++;
    j = i;
    while (line[j] && line[j] != ' ')
        j++;
    if (line[j])
        cub3d_error("Invalid file");
    *texture = ft_substr(line, i, j - i);
}

void    parse_color(char *line, int *color)
{
    int     i;
    int     j;
    int     r;
    int     g;
    int     b;

    i = 0;
    while (line[i] && line[i] != ' ')
        i++;
    while (line[i] && line[i] == ' ')
        i++;
    j = i;
    while (line[j] && line[j] != ',')
        j++;
    if (!line[j])
        cub3d_error("Invalid file");
    r = ft_atoi(line + i);
    i = j + 1;
    j = i;
    while (line[j] && line[j] != ',')
        j++;
    if (!line[j])
        cub3d_error("Invalid file");
    g = ft_atoi(line + i);
    i = j + 1;
    j = i;
    while (line[j] && line[j] != ' ')
        j++;
    if (line[j])
        cub3d_error("Invalid file");
    b = ft_atoi(line + i);
    *color = (r << 16) | (g << 8) | b;
}

// void    parse_map(t_cube *info, char *line)
// {
//     int     i;
//     int     j;

//     i = 0;
//     while (line[i] && line[i] == ' ')
//         i++;
//     j = i;
//     while (line[j] && line[j] != ' ')
//         j++;
//     if (line[j])
//         cub3d_error("Invalid file");
//     if (!info->map)
//     {
//         info->map = malloc(sizeof(t_map));
//         if (!info->map)
//             cub3d_error("Malloc failed");
//         info->map->map = malloc(sizeof(char *));
//         if (!info->map->map)
//             cub3d_error("Malloc failed");
//         info->map->map[0] = ft_strdup(line + i);
//         info->map->width = ft_strlen(line + i);
//         info->map->height = 1;
//     }
//     else
//     {
//         info->map->map = ft_realloc(info->map->map,
//             sizeof(char *) * info->map->height,
//             sizeof(char *) * (info->map->height + 1));
//         if (!info->map->map)
//             cub3d_error("Malloc failed");
//         info->map->map[info->map->height] = ft_strdup(line + i);
//         info->map->height++;
//     }
// }

void    parse_file(t_cube   *info)
{
    char    *line;
    // int     ret;

    while ((line = get_next_line(info->fd)) > 0)
    {
        if (ft_strlen(line) > 0 && line[0] != ' ')
        {
            // if (line[0] == 'R')
            //     parse_resolution(info, line);
            printf("line: {%s}\n", line);
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
            else if (line[0] == '1')
                printf("map\n");
                // parse_map(info, line);
            // else
            //     cub3d_error("Invalid file");
        }
        free(line);
    }
    // if (line == -1)
    //     cub3d_error("Invalid file");
    free(line);
}
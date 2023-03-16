#include "cub3d.h"

void    cub3d_error(char *msg)
{
    ft_putstr_fd("Error", 2);
    if (msg)
    {
        ft_putstr_fd(": ", 2);
        ft_putstr_fd(msg, 2);
    }
    exit(1);
}

void    cub3d_parse(t_cube *info)
{
    parse_file(info);
    close(info->fd);
}

void    cub3d_init(t_cube *info, char *file)
{
    info->fd = open(file, O_RDONLY);
    if (info->fd == -1)
        cub3d_error("Invalid file");
    info->north = NULL;
    info->south = NULL;
    info->west = NULL;
    info->east = NULL;
    info->floor = -1;
    info->ceiling = -1;
    info->map = NULL;
    info->map_width = 0;
    info->map_height = 0;
}

int main(int argc, char **argv)
{
    t_cube info;
    char *ext;

    ext = ".cub";
    if (argc == 2 && ft_strlen(argv[1]) >= ft_strlen(ext))
    {
        if (ft_strncmp(argv[1] + ft_strlen(argv[1])
            - ft_strlen(ext), ext, ft_strlen(ext)))
            cub3d_error("Invalid file extension");
        cub3d_init(&info, argv[1]);
        cub3d_parse(&info);
        // cub3d_render(&info);
        // cub3d_destroy(&info);
    }
    else
        cub3d_error("Invalid number of arguments");
    return (0);
}
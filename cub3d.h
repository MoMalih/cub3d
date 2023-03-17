#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "libft/libft.h"
// #include "mlx/mlx.h"
#include "get_next_line/get_next_line.h"

// #define BUFFER_SIZE 1
#define SPACE ' '

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
}               t_map;

typedef struct s_cube
{
    int     fd;
    char    *north;
    char    *south;
    char    *west;
    char    *east;
    int     floor;
    int     ceiling;
    char    **map;
    int     map_width;
    int     map_height;
}               t_cube;

void    parse_file(t_cube   *info);
void    cub3d_error(char *msg);


#endif 

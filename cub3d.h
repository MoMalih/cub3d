#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

typedef struct s_cube
{
    int     fd;
    char    *north;
    char    *south;
    char    *west;
    char    *east;
    int     floor;
    int     ceiling;
    t_map   *map;
    int     map_width;
    int     map_height;
}               t_cube;

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
}               t_map;

#endif 

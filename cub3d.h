/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 04:10:09 by zbidouli          #+#    #+#             */
/*   Updated: 2023/04/04 04:48:28 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     CUB3D_H
# define    CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
// #include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

// #define BUFFER_SIZE 1
# define SPACE ' '

typedef struct s_cube
{
	int		fd;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	**map;
	int		floor;
	int		ceiling;
	int		map_width;
	int		map_height;
}	t_cube;

void	parse_file(t_cube *info);
void	cub3d_error(char *msg);
void	check_map(t_cube *info);
void	*ft_realloc(void *ptr, size_t size);
void	search_r(char	**map, int h, int w);
void	search_l(char	**map, int h, int w);
void	search_t(char	**map, int h, int w);
void	search_d(char **map, int h, int w, int height);
int		set_width(char **map, int height);
void	complete_map(t_cube *info);

#endif 

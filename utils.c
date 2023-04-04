/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:59:41 by zbidouli          #+#    #+#             */
/*   Updated: 2023/04/04 04:07:16 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_r(char	**map, int h, int w)
{
	while (map[h][++w] == ' ')
		;
	if (h > 0 && w >= 0 && map[h][w] != '1' && map[h][w] != '\0')
		cub3d_error("Map is not closed/surrounded by walls.\n");
}

void	search_l(char	**map, int h, int w)
{
	while (map[h][--w] == ' ' && w >= 0)
		;
	if (h > 0 && w >= 0 && map[h][w] != '1' && map[h][w] != '\0')
		cub3d_error("Map is not closed/surrounded by walls.\n");
}

void	search_t(char	**map, int h, int w)
{
	while (map[--h][w] == ' ' && h > 0)
		;
	if (h > 0 && w >= 0 && map[h][w] != '1')
		cub3d_error("Map is not closed/surrounded by walls.\n");
}

void	search_d(char **map, int h, int w, int height)
{
	while (h < height -1 && map[++h][w] == ' ')
		;
	if (h != (height - 1) && w >= 0 && map[h][w] != '1')
		cub3d_error("Map is not closed/surrounded by walls.");
}

void	*ft_realloc(void	*ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0)
	{
		free(ptr);
		cub3d_error("REALLOC_FAIL");
	}
	if (ptr == NULL)
		return (malloc(size));
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		cub3d_error("REALLOC_FAIL");
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

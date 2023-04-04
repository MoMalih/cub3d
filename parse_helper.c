/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 04:47:12 by zbidouli          #+#    #+#             */
/*   Updated: 2023/04/04 04:48:02 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_width(char **map, int height)
{
	int	it1;
	int	w;

	it1 = -1;
	w = 0;
	while (++it1 < height)
	{
		if (ft_strlen(&map[it1][0]) > w)
			w = ft_strlen(&map[it1][0]);
	}
	return (w);
}

void	complete_map(t_cube *info)
{
	int	it;
	int	it1;

	it = -1;
	while (++it < info->map_height)
	{
		if (ft_strlen(info->map[it]) < info->map_width)
		{
			info->map[it] = ft_realloc(info->map[it],
					sizeof(char) * info->map_width);
			it1 = ft_strlen(info->map[it]) - 1;
			while (++it1 < info->map_width)
				info->map[it][it1] = ' ';
			info->map[it][it1] = '\0';
		}
	}
}

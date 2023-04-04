/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbidouli <zbidouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:44:41 by zbidouli          #+#    #+#             */
/*   Updated: 2023/04/04 04:29:59 by zbidouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check if map is enclosed by walls wall = 1

void	edge(char	*line)
{
	int	j;

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

void	space_check(t_cube	*info, int i)
{
	int	it;

	it = -1;
	if (info->map[i][0] == '0')
		cub3d_error("Map is not closed/surrounded by walls.");
	while (++it < ft_strlen(&info->map[i][0]))
	{
		if (info->map[i][it] == ' ' && i > 0
				&& i < info->map_height)
		{
			search_r(info->map, i, it);
			search_l(info->map, i, it);
			search_t(info->map, i, it);
			search_d(info->map, i, it, info->map_height);
		}
	}
}

void	inputs(t_cube	*info)
{
	int	it;
	int	it1;
	int	flag;

	it = -1;
	flag = 0;
	while (++it < info->map_height)
	{
		it1 = -1;
		while (++it1 <= ft_strlen(&info->map[it][0]) && info->map[it][it1])
		{
			if (info->map[it][it1] == 'N' || info->map[it][it1] == 'E'
				|| info->map[it][it1] == 'W' || info->map[it][it1] == 'S')
				flag = 1;
			else
			{
				if (info->map[it][it1] != '0' && info->map[it][it1] != '1'
					&& info->map[it][it1] != ' ' )
					cub3d_error("undefined map file");
			}
		}
	}
	if (!flag)
		cub3d_error("please add a player");
}

void	check_map(t_cube	*info)
{
	int	i;

	inputs(info);
	if (info->map[0][0] && info->map[info->map_height - 1][0])
	{
		edge(&info->map[0][0]);
		edge(&info->map[info->map_height - 1][0]);
	}
	i = 0;
	while (++i < info->map_height)
	{
		if (ft_strchr(&info->map[i][0], SPACE))
			space_check(info, i);
		else
			if (info->map[i][0] != '1' ||
				info->map[i][ft_strlen(&info->map[i][0]) - 1] != '1')
				cub3d_error("Map is not surro  unded by walls.\n");
	}
}

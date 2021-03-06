/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 05:00:54 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/01 17:27:26 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_find_pos(char **map, char c, int type)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				if (type == 1)
					return (x);
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_charcmp(char a, char b)
{
	if (b == 'N' || b == 'W' || b == 'E' || b == 'S')
		return (0);
	else if (a == 'N' || a == 'W' || a == 'E' || a == 'S')
		return (0);
	else if (a - b == 0 || a - b == -1)
		return (0);
	return (42);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 05:03:02 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/28 05:07:25 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_check_zero(char **map, int y, int x)
{
	while (map[y])
	{
		while (map[y][x] && x <= ft_strlen2(map[y]))
		{
			if (map[y][x] == '0' && x > ft_strlen2(map[y - 1]))
				return (false);
			else if (map[y][x] == '0' && x > ft_strlen2(map[y + 1]))
				return (false);
			else if (map[y][x] == '0' && ft_charcmp(map[y][x], map[y - 1][x]))
				return (false);
			else if (map[y][x] == '0' && ft_charcmp(map[y][x], map[y + 1][x]))
				return (false);
			else if (map[y][x] == '0' && ft_charcmp(map[y][x], map[y][x + 1]))
				return (false);
			else if (map[y][x] == '0' && ft_charcmp(map[y][x], map[y][x - 1]))
				return (false);
			x++;
		}
		x = 0;
		y++;
	}
	return (true);
}

int	ft_check_first_last_line(char **map, int y, int x)
{
	if (!*map)
		ft_exit(false);
	while (map[y][x] && x < (int)ft_strlen(map[y]) - 2)
	{
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (false);
		x++;
	}
	x = 0;
	while (map[y])
		y++;
	y -= 1;
	while (map[y][x] && x <= (int)ft_strlen2(map[y]) - 1)
	{
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (false);
		x++;
	}
	return (true);
}

int	ft_check_col(char **map, int i, int j)
{
	while (map[i])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (false);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][(int)ft_strlen(map[i]) - 2] != '1')
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_player(char **map, int i, int j)
{
	int	value;

	value = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				value++;
			j++;
		}
		i++;
	}
	return (value);
}

int	ft_check_content(char **map, int i, int j)
{
	if (ft_check_player(map, 0, 0) != 1)
		return (false);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] !=
				'E' && map[i][j] != 'W' && map[i][j] != '\n')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 01:25:56 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/04 21:32:57 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	ft_find_what(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S'
				|| map[i][j] == 'W')
				return (map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_start_dir(t_vars *vars)
{
	char	type;

	type = ft_find_what(vars->map);
	if (type == 'S')
		return (90);
	else if (type == 'O')
		return (180);
	else if (type == 'N')
		return (270);
	else if (type == 'E')
		return (360);
	return (0);
}

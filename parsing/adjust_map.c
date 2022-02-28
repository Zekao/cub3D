/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:05:23 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/28 17:57:39 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char    **ft_create_new(char **map, int i)
{
	int		size;
	int		full_size;
	char	**new;
	
	size = 0;
	full_size = ft_strstrlen(map);
	new = ft_malloc(sizeof(char *) * (full_size - i) + 1);
	while (size < full_size - i - 1)
	{
		new[size] = ft_strdup(map[i + size + 1]);
		size++;
	}
	new[size] = '\0';
	return (new);
}

char    **adjust_map(char **map)
{
	char    **new_map;
	int     i;

	i = 0;
	while (map[i] && ft_check_line(map[i]) == false)
		i++;
	if (ft_check_line(map[i]) == true)
	{
		new_map = ft_create_new(map, i);
		return (new_map);
	}
	return (NULL);
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && i < ft_strlen2(line) - 2)
	{
		if (line[i] != '1' && line[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:05:23 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/06 23:03:11 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

char	**ft_create_new(char **map, int i)
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
	size = -1;
	while (map[++size])
		ft_free(map[size]);
	return (new);
}

char	**adjust_map(char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	while (map[i] && ft_check_line(map[i]) == false)
		i++;
	if (ft_check_line(map[i]) == true)
		return (new_map = ft_create_new(map, i), new_map);
	return (NULL);
}

char	**ft_search_replace(char **new_map, char **map, int i, int j)
{
	char	type;

	type = ft_find_what(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == type || map[i][j] == '2')
				new_map[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (new_map);
}

char	**ft_fill_new(char **map)
{
	int		i;
	int		j;
	int		size;
	int		max_size;
	char	**new_map;

	i = 0;
	j = 0;
	size = ft_strstrlen(map);
	max_size = ft_get_col(map);
	new_map = ft_malloc(sizeof(char *) * (size + 1));
	if (!new_map)
		return (NULL);
	while (i < size)
	{
		new_map[i] = ft_malloc(sizeof(char) * (max_size + 1));
		new_map[i] = ft_memset(new_map[i], '1', max_size);
		new_map[i][max_size] = '\0';
		i++;
	}
	new_map[i] = '\0';
	i = 0;
	new_map = ft_search_replace(new_map, map, i, j);
	return (new_map);
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

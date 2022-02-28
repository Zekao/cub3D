/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 05:01:37 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/28 17:32:59 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_get_size(char *file)
{
	int		fd;
	int		size;
	char	*tmp;

	size = 0;
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	size++;
	while (tmp)
	{
		ft_free(tmp);
		tmp = get_next_line(fd);
		size++;
	}
	ft_free(tmp);
	return (size);
}

char	**recover_map(char *file)
{
	char	**map;
	int		fd;
	int		i;
	int		size;

	i = 0;
	fd = open(file, O_RDONLY);
	size = ft_get_size(file);
	map = ft_malloc(sizeof(char *) * size + 1);
	while (i < size - 1)
	{
		map[i] = get_next_line(fd);
		// printf("%s", map[i]);
		i++;
	}
	map[i] = '\0';
	close(fd);
	return (map);
}

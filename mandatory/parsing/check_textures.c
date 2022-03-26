/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:34:20 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/04 23:47:28 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_init_path(t_path *path)
{
	path->no = 0;
	path->so = 0;
	path->we = 0;
	path->ea = 0;
	path->f = 0;
	path->c = 0;
}

int	ft_update_path(char **map, t_path *path, int i)
{
	if (ft_strncmp(map[i], "NO ", 3) == 0)
		return (path->no_path = ft_strdup(map[i] + 3), path->no++, true);
	else if (ft_strncmp(map[i], "SO ", 3) == 0)
		return (path->so_path = ft_strdup(map[i] + 3), path->so++, true);
	else if (ft_strncmp(map[i], "WE ", 3) == 0)
		return (path->we_path = ft_strdup(map[i] + 3), path->we++, true);
	else if (ft_strncmp(map[i], "EA ", 3) == 0)
		return (path->ea_path = ft_strdup(map[i] + 3), path->ea++, true);
	else if (ft_strncmp(map[i], "F ", 2) == 0)
		return (path->f++, true);
	else if (ft_strncmp(map[i], "C ", 2) == 0)
		return (path->c++, true);
	return (false);
}

int	ft_check_textures(char **map, t_path *path)
{
	int	i;

	i = 0;
	ft_init_path(path);
	while (map[i] && path->no < 2 && path->so < 2 && path->we < 2
		&& path->ea < 2 && path->f < 2 && path->c < 2)
	{
		if (ft_update_path(map, path, i) == true)
			;
		else if (ft_strncmp(map[i], "1", 1) != 0
			&& ft_strncmp(map[i], "0", 1) != 0
			&& ft_strncmp(map[i], "\n", 1) != 0
			&& ft_strncmp(map[i], " ", 1) != 0)
			return (false);
		i++;
	}
	if (path->no != 1 || path->so != 1 || path->we != 1 || path->ea != 1
		|| path->f != 1 || path->c != 1)
		return (false);
	return (true);
}

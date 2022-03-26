/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 00:53:41 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/03 01:03:32 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_get_col(char **map)
{
	size_t	res;
	int		i;

	i = 0;
	res = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > res)
			res = ft_strlen(map[i]);
		i++;
	}
	return (res);
}

int	ft_get_row(char **map)
{
	return (ft_strstrlen(map));
}

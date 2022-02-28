/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:34:20 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/28 18:08:21 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int ft_check_textures(char **map)
{
	int i;
	int	F;
	int	C;
	int NO;
	int SO;
	int WE;
	int EA;
	
	NO = 0;
	SO = 0;
	WE = 0;
	EA = 0;
	i = 0;
	F = 0;
	C = 0;
	while (map[i] && NO < 2 && SO < 2 && WE < 2 && EA < 2 && F < 2 && C < 2)
	{
		if (ft_strncmp(map[i], "NO", 2) == 0)
			NO++;
		else if (ft_strncmp(map[i], "SO", 2) == 0)
			SO++;
		else if (ft_strncmp(map[i], "WE", 2) == 0)
			WE++;
		else if (ft_strncmp(map[i], "EA", 2) == 0)
			EA++;
		else if (ft_strncmp(map[i], "F", 1) == 0)
			F++;
		else if (ft_strncmp(map[i], "C", 1) == 0)
			C++;
		else if (ft_strncmp(map[i], "1", 1) != 0 && ft_strncmp(map[i], "0", 1) != 0 && ft_strncmp(map[i], "\n", 1) !=0 && ft_strncmp(map[i], " ", 1) != 0)
			return (false);
		i++;	
	}
	if (NO != 1 || SO != 1 || WE != 1 || EA != 1 || F != 1 || C != 1)
		return (false);
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:11:15 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/28 18:20:07 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	main(int argc, char **argv)
{
	char	**map;
	
	if (argc == 2)
	{
		ft_parse_cub(argv[1]);
		map = recover_map(argv[1]);
		if (ft_check_textures(map) == false)
			exit_failure("Problem in the map textures");
		map = adjust_map(map);
		if (ft_check_first_last_line(map, 0, 0) == false)
			exit_failure("error in the map ?");
		if (ft_check_col(map, 0, 0) == false)
			exit_failure("error in the map !");
		if (ft_check_content(map, 0, 0) == false)
			exit_failure("error in the map /");
		if (ft_check_zero(map, 1, 0) == false)
			exit_failure("error in the map !!");
	}
}

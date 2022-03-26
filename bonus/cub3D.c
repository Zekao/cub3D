/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:11:15 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/06 23:07:50 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static char	*ft_get_text(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][j] == c)
			return (ft_strdup(map[i]) + 2);
		i++;
	}
	return (NULL);
}

void	ft_init_map(t_vars *vars, char **argv)
{
	ft_parse_cub(argv[1]);
	vars->map = recover_map(argv[1]);
	if (ft_check_textures(vars->map, &vars->path) == false)
		exit_failure("Problem in the textures of the map");
	vars->path.c_path = ft_get_text(vars->map, 'C');
	vars->path.f_path = ft_get_text(vars->map, 'F');
	vars->map = adjust_map(vars->map);
	if (ft_check_first_last_line(vars->map, 0, 0) == false)
		exit_failure("error in the map (first line)");
	if (ft_check_col(vars->map, 0, 0) == false)
		exit_failure("error in the map (column)");
	if (ft_check_content(vars->map, 0, 0) == false)
		exit_failure("error in the map (content)");
	if (ft_check_zero(vars->map, 1, 0) == false
		&& ft_check_bonus(vars->map) == false)
		exit_failure("error in the map");
	vars->map = ft_fill_new(vars->map);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		ft_init_map(&vars, argv);
		ft_init(&vars);
	}
}

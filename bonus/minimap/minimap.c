/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:54:12 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/06 23:08:09 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	print_close_map(t_data *img, int x, int y, int som)
{
	int	size;
	int	size2;

	size = x * som;
	while (size % som < som - 1)
	{
		size2 = y * som;
		while (size2++ % som < som - 1)
			img_pix_put(img, x + size, y + size2, 0xFF0000FF);
		size++;
	}
}

void	print_open_map(t_data *img, int x, int y, int som)
{
	int	size;
	int	size2;

	size = x * som;
	while (size % som < som - 1)
	{
		size2 = y * som;
		while (size2++ % som < som - 1)
			img_pix_put(img, x + size, y + size2, 0xFF00FF00);
		size++;
	}
}

void	print_wall_map(t_data *img, int x, int y, int som)
{
	int	size;
	int	size2;

	size = x * som;
	while (size % som < som - 1)
	{
		size2 = y * som;
		while (size2++ % som < som - 1)
			img_pix_put(img, x + size, y + size2, 0xFFFFFFFF);
		size++;
	}
}

void	print_floor_map(t_data *img, int x, int y, int som)
{
	int	size;
	int	size2;

	size = x * som;
	while (size % som < som - 1)
	{
		size2 = y * som;
		while (size2++ % som < som - 1)
			img_pix_put(img, x + size, y + size2, 0xFFFF0000);
		size++;
	}
}

void	ft_minimap(t_vars *vars, t_data *img, int x, int y)
{
	int	som;

	som = 120 / ft_strstrlen(vars->map);
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
				print_wall_map(img, x, y, som);
			else if (vars->map[y][x] == '2')
				print_close_map(img, x, y, som);
			else if (vars->map[y][x] == '3')
				print_open_map(img, x, y, som);
			else if (vars->map[y][x] != '1')
				print_floor_map(img, x, y, som);
			x++;
		}
		y++;
	}
}

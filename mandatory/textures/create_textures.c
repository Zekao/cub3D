/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:43:32 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/06 03:38:56 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	reasign_path(t_vars *vars)
{
	vars->path.we_path = ft_substr(vars->path.we_path, 0,
			ft_strlen(vars->path.we_path) - 1);
	vars->path.no_path = ft_substr(vars->path.no_path, 0,
			ft_strlen(vars->path.no_path) - 1);
	vars->path.so_path = ft_substr(vars->path.so_path, 0,
			ft_strlen(vars->path.so_path) - 1);
	vars->path.ea_path = ft_substr(vars->path.ea_path, 0,
			ft_strlen(vars->path.ea_path) - 1);
}

void	ft_create_textures(t_vars *vars)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	reasign_path(vars);
	vars->texture_left = mlx_xpm_file_to_image(vars->mlx,
			vars->path.we_path, &a, &b);
	if (!vars->texture_left)
		exit_failure2("problem in the textures path", vars);
	vars->texture_right = mlx_xpm_file_to_image(vars->mlx,
			vars->path.ea_path, &a, &b);
	if (!vars->texture_right)
		exit_failure2("problem in the textures path", vars);
	vars->texture_up = mlx_xpm_file_to_image(vars->mlx,
			vars->path.so_path, &a, &b);
	if (!vars->texture_up)
		exit_failure2("problem in the texture path", vars);
	vars->texture_down = mlx_xpm_file_to_image(vars->mlx,
			vars->path.no_path, &a, &b);
	if (!vars->texture_down)
		exit_failure2("problem in the texture path", vars);
}

void	init_texture_x(t_vars *vars, t_data *texture, int x)
{
	if (vars->rays[x].was_hit_vertical)
		texture->texture_offset_x = (int)vars->rays[x].wall_hit_y % TILE_SIZE;
	else
		texture->texture_offset_x = (int)vars->rays[x].wall_hit_x % TILE_SIZE;
}

void	calculate_texture_y(t_render_3d three_d, t_data *texture, int y, int i)
{
	int	i2;
	int	distance_from_top;

	i2 = -1;
	distance_from_top = y + (three_d.wall_strip_h / 2) - (WIN_H / 2);
	texture->texture_offset_y = distance_from_top
		* ((float)TEXTURE_HEIGHT / three_d.wall_strip_h);
	while (++i2 != i)
		texture->colors[i2] = texture->wall[i2][(TEXTURE_WIDTH
				* texture->texture_offset_y) + texture->texture_offset_x];
}

void	init_texture(t_vars *vars, t_data *texture)
{
	texture->wall[0] = (unsigned int *)mlx_get_data_addr(vars->texture_down,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	texture->wall[1] = (unsigned int *)mlx_get_data_addr(vars->texture_up,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	texture->wall[2] = (unsigned int *)mlx_get_data_addr(vars->texture_left,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	texture->wall[3] = (unsigned int *)mlx_get_data_addr(vars->texture_right,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
}

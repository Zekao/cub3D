/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:06:43 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/06 20:58:01 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RayCasting.h>

bool	is_inside_map(t_vars *vars, float x, float y)
{
	return (x >= 0 && x <= ft_get_col(vars->map) * TILE_SIZE
		&& y >= 0 && y <= ft_get_row(vars->map) * TILE_SIZE);
}

int	get_map_at(char **map, int y, int x)
{
	return (map[y][x]);
}

bool	map_wall_at(t_vars *vars, float x, float y)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	if (x < 0 || x >= ft_get_col(vars->map) * TILE_SIZE)
		return (true);
	if (y < 0 || y >= ft_get_row(vars->map) * TILE_SIZE)
		return (true);
	map_grid_index_x = floor(x / TILE_SIZE);
	map_grid_index_y = floor(y / TILE_SIZE);
	if (vars->map[map_grid_index_y][map_grid_index_x] != 0
		&& vars->map[map_grid_index_y][map_grid_index_x] != '1'
		&& vars->map[map_grid_index_y][map_grid_index_x] != '2')
		return (false);
	return (true);
}

void	choose_smallest_distance(t_vars *vars, t_rays_dis *horz,
									t_rays_dis *vert, t_rays *rays)
{
	if (horz->found_wall_hit)
		horz->hit_distance = distance_between_points(vars->player.posx,
				vars->player.posy, horz->wall_hit_x,
				horz->wall_hit_y);
	else
		horz->hit_distance = FLT_MAX;
	if (vert->found_wall_hit)
		vert->hit_distance = distance_between_points(vars->player.posx,
				vars->player.posy, vert->wall_hit_x,
				vert->wall_hit_y);
	else
		vert->hit_distance = FLT_MAX;
	rays->distance = horz->hit_distance;
	rays->wall_hit_x = horz->wall_hit_x;
	rays->wall_hit_y = horz->wall_hit_y;
	rays->wall_hit_content = horz->wall_content;
	rays->was_hit_vertical = false;
	if (vert->hit_distance < horz->hit_distance)
	{
		rays->distance = vert->hit_distance;
		rays->wall_hit_x = vert->wall_hit_x;
		rays->wall_hit_y = vert->wall_hit_y;
		rays->wall_hit_content = vert->wall_content;
		rays->was_hit_vertical = true;
	}
}

void	calculate_xy_steps(int flag, t_rays_c *rays_c, t_rays_dis *dist,
															float ray_angle)
{
	if (flag == 1)
	{
		rays_c->ystep = TILE_SIZE;
		check_horzrays_facing(1, rays_c);
		rays_c->xstep = TILE_SIZE / tan(ray_angle);
		check_horzrays_facing(2, rays_c);
	}
	else
	{
		rays_c->xstep = TILE_SIZE;
		check_vertrays_facing(1, rays_c);
		rays_c->ystep = TILE_SIZE * tan(ray_angle);
		check_vertrays_facing(2, rays_c);
	}
	dist->nexttouch_x = rays_c->xintercept;
	dist->nexttouch_y = rays_c->yintercept;
}

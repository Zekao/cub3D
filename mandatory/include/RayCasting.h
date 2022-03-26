/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RayCasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:08:19 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/04 22:02:46 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include <cub3D.h>

void	cast_all_rays(t_vars *vars);
void	cast_rays(t_vars *vars, float ray_angle, t_rays *rays);
void	choose_smallest_distance(t_vars *vars, t_rays_dis *horz,
			t_rays_dis *vert, t_rays *rays);
bool	map_wall_at(t_vars *vars, float x, float y);

bool	is_inside_map(t_vars *vars, float x, float y);
int		get_map_at(char **map, int y, int x);

void	check_horzrays_facing(int flag, t_rays_c *rays_c);
void	check_vertrays_facing(int flag, t_rays_c *rays_c);
void	found_wall(t_vars *vars, t_rays_dis *dist, t_rays_c *rays_c);

void	ft_init_facing_value(float ray_angle, t_rays_c *rays_c);
void	ft_init_rays_value(t_rays_dis *rays_dis);
void	calculate_xy_steps(int flag, t_rays_c *rays_c, t_rays_dis *dist,
			float ray_angle);
void	generate3d_projection(t_vars *vars);
void	ft_player_move(t_vars *vars);

#endif

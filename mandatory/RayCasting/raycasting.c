/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 23:15:31 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/04 21:46:04 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RayCasting.h>

void	ft_horizontal_rays(t_vars *vars, t_rays_dis *horz, t_rays_c *rays_c,
																float ray_angle)
{
	rays_c->yintercept = floor(vars->player.posy / TILE_SIZE) * TILE_SIZE;
	if (rays_c->is_ray_facing_down)
		rays_c->yintercept += TILE_SIZE;
	rays_c->xintercept = vars->player.posx + (rays_c->yintercept
			- vars->player.posy) / tan(ray_angle);
	calculate_xy_steps(1, rays_c, horz, ray_angle);
	while (is_inside_map(vars, horz->nexttouch_x, horz->nexttouch_y))
	{
		rays_c->x_to_check = horz->nexttouch_x;
		rays_c->y_to_check = horz->nexttouch_y;
		if (rays_c->is_ray_facing_up)
			rays_c->y_to_check += -1;
		if (map_wall_at(vars, rays_c->x_to_check, rays_c->y_to_check))
		{
			found_wall(vars, horz, rays_c);
			return ;
		}
		else
		{
			horz->nexttouch_x += rays_c->xstep;
			horz->nexttouch_y += rays_c->ystep;
		}
	}
}

void	ft_vertical_rays(t_vars *vars, t_rays_dis *vert, t_rays_c *rays_c,
															float ray_angle)
{
	rays_c->xintercept = floor(vars->player.posx / TILE_SIZE) * TILE_SIZE;
	if (rays_c->is_ray_facing_right)
		rays_c->xintercept += TILE_SIZE;
	rays_c->yintercept = vars->player.posy + (rays_c->xintercept
			- vars->player.posx) * tan(ray_angle);
	calculate_xy_steps(0, rays_c, vert, ray_angle);
	while (is_inside_map(vars, vert->nexttouch_x, vert->nexttouch_y))
	{
		rays_c->x_to_check = vert->nexttouch_x;
		if (rays_c->is_ray_facing_left)
			rays_c->x_to_check += -1;
		rays_c->y_to_check = vert->nexttouch_y;
		if (map_wall_at(vars, rays_c->x_to_check, rays_c->y_to_check))
		{
			found_wall(vars, vert, rays_c);
			return ;
		}
		else
		{
			vert->nexttouch_x += rays_c->xstep;
			vert->nexttouch_y += rays_c->ystep;
		}
	}
}

void	cast_rays(t_vars *vars, float ray_angle, t_rays *rays)
{
	t_rays_dis	vert;
	t_rays_dis	horz;
	t_rays_c	rays_c;

	ray_angle = normalizeangle(ray_angle);
	ft_init_facing_value(ray_angle, &rays_c);
	ft_init_rays_value(&horz);
	ft_horizontal_rays(vars, &horz, &rays_c, ray_angle);
	ft_init_rays_value(&vert);
	ft_vertical_rays(vars, &vert, &rays_c, ray_angle);
	choose_smallest_distance(vars, &horz, &vert, rays);
	rays->ray_angle = ray_angle;
	rays->is_ray_facing_up = rays_c.is_ray_facing_up;
	rays->is_ray_facing_down = rays_c.is_ray_facing_down;
	rays->is_ray_facing_right = rays_c.is_ray_facing_right;
	rays->is_ray_facing_left = rays_c.is_ray_facing_left;
}

void	cast_all_rays(t_vars *vars)
{
	float	ray_angle;
	t_rays	*rays;
	int		col;

	col = 0;
	ray_angle = vars->player.rotation_angle + atan((col - NUM_RAYS / 2)
			/ ((WIN_W / 2) / tan((120 * (M_PI / 180)) / 2)));
	rays = (t_rays *)ft_malloc(sizeof(t_rays) * NUM_RAYS + 1);
	while (col < NUM_RAYS)
	{
		cast_rays(vars, ray_angle, &rays[col]);
		ray_angle = vars->player.rotation_angle + atan((col - NUM_RAYS / 2)
				/ ((WIN_W / 2) / tan((120 * (M_PI / 180)) / 2)));
		col++;
	}
	vars->rays = rays;
}

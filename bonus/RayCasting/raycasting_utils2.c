/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:06:43 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/04 22:11:13 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RayCasting.h>

void	check_horzrays_facing(int flag, t_rays_c *rays_c)
{
	if (flag == 1)
	{
		if (rays_c->is_ray_facing_up)
			rays_c->ystep *= -1;
		else
			rays_c->ystep *= 1;
	}
	if (flag == 2)
	{
		if (rays_c->is_ray_facing_left && rays_c->xstep > 0)
			rays_c->xstep *= -1;
		else
			rays_c->xstep *= 1;
		if (rays_c->is_ray_facing_right && rays_c->xstep < 0)
			rays_c->xstep *= -1;
		else
			rays_c->xstep *= 1;
	}
}

void	check_vertrays_facing(int flag, t_rays_c *rays_c)
{
	if (flag == 1)
	{
		if (rays_c->is_ray_facing_left)
			rays_c->xstep *= -1;
		else
			rays_c->xstep *= 1;
	}
	if (flag == 2)
	{
		if (rays_c->is_ray_facing_up && rays_c->ystep > 0)
			rays_c->ystep *= -1;
		else
			rays_c->ystep *= 1;
		if (rays_c->is_ray_facing_down && rays_c->ystep < 0)
			rays_c->ystep *= -1;
		else
			rays_c->ystep *= 1;
	}
}

void	found_wall(t_vars *vars, t_rays_dis *dist, t_rays_c *rays_c)
{
	dist->wall_hit_x = dist->nexttouch_x;
	dist->wall_hit_y = dist->nexttouch_y;
	dist->wall_content = get_map_at(vars->map, (int)floor(rays_c->y_to_check
				/ TILE_SIZE), (int)floor(rays_c->x_to_check / TILE_SIZE));
	dist->found_wall_hit = true;
}

void	ft_init_facing_value(float ray_angle, t_rays_c *rays_c)
{
	rays_c->is_ray_facing_down = (ray_angle > 0 && ray_angle < M_PI);
	rays_c->is_ray_facing_up = !rays_c->is_ray_facing_down;
	rays_c->is_ray_facing_right = (ray_angle < 0.5 * M_PI
			|| ray_angle > 1.5 * M_PI);
	rays_c->is_ray_facing_left = !rays_c->is_ray_facing_right;
}

void	ft_init_rays_value(t_rays_dis *rays_dis)
{
	rays_dis->found_wall_hit = false;
	rays_dis->wall_hit_x = 0;
	rays_dis->wall_hit_y = 0;
	rays_dis->wall_content = 0;
}

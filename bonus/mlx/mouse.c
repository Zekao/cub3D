/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:07:19 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/06 23:22:37 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <RayCasting.h>

void	ft_mouse(t_vars *vars)
{
	int	posx;
	int	posy;

	if (vars->toggle_mouse == true)
	{
		mlx_mouse_get_pos(vars->mlx, vars->win, &posx, &posy);
		if (posx < vars->win_x / 3)
			vars->player.turn_direction = -1;
		else if (posx > vars->win_x / 3 * 2)
			vars->player.turn_direction = 1;
		else
			vars->player.turn_direction = 0;
	}
}

void	rl_dir(t_vars *vars, float *new_x, float *new_y)
{
	float	move_step;

	if (vars->player.rl_direction != 0)
	{
	move_step = vars->player.rl_direction * vars->player.walk_speed;
	*new_x = vars->player.posx + -sin(vars->player.rotation_angle)
			* move_step;
	*new_y = vars->player.posy + cos(vars->player.rotation_angle)
			* move_step;
	}
}

void	ft_player_move(t_vars *vars)
{
	float	move_step;
	float	new_x;
	float	new_y;

	vars->player.rotation_angle += vars->player.turn_direction
		* vars->player.turn_speed;
	move_step = vars->player.walk_direction * vars->player.walk_speed;
	new_x = vars->player.posx + cos(vars->player.rotation_angle) * move_step;
	new_y = vars->player.posy + sin(vars->player.rotation_angle) * move_step;
	rl_dir(vars, &new_x, &new_y);
	if (!map_door_at(vars, new_x, new_y, '2') && vars->door == true)
	{
		vars->map[(int)floor(new_y / TILE_SIZE)]
		[(int)floor(new_x / TILE_SIZE)] = '3';
		vars->door = false;
	}
	else if (!map_door_at(vars, new_x, new_y, '3') && vars->door == true)
		vars->map[(int)floor(new_y / TILE_SIZE)]
		[(int)floor(new_x / TILE_SIZE)] = '2';
	if (!map_wall_at(vars, new_x, new_y))
	{
		vars->player.posx = new_x;
		vars->player.posy = new_y;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 20:37:23 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/06 18:46:14 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <RayCasting.h>

int	ft_close(t_vars *vars)
{
	ft_free(vars->map);
	mlx_destroy_image(vars->mlx, vars->texture_up);
	mlx_destroy_image(vars->mlx, vars->texture_down);
	mlx_destroy_image(vars->mlx, vars->texture_right);
	mlx_destroy_image(vars->mlx, vars->texture_left);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	printf("Closed\n");
	ft_exit (0);
	return (0);
}

int	key_press(int kc, t_vars *vars)
{
	if (kc == XK_Escape)
		ft_close(vars);
	else if (kc == XK_Up || kc == XK_w)
		vars->player.walk_direction = 1;
	else if (kc == XK_Right)
		vars->player.turn_direction = 1;
	else if (kc == XK_Left)
		vars->player.turn_direction = -1;
	else if (kc == XK_Down || kc == XK_s)
		vars->player.walk_direction = -1;
	else if (kc == XK_d)
		vars->player.rl_direction = 1;
	else if (kc == XK_a)
		vars->player.rl_direction = -1;
	return (1);
}

int	key_release(int kc, t_vars *vars)
{
	if (kc == XK_Up || kc == XK_w)
		vars->player.walk_direction = 0;
	else if (kc == XK_Right)
		vars->player.turn_direction = 0;
	else if (kc == XK_Left)
		vars->player.turn_direction = 0;
	else if (kc == XK_Down || kc == XK_s)
		vars->player.walk_direction = 0;
	else if (kc == XK_a)
		vars->player.rl_direction = 0;
	else if (kc == XK_d)
		vars->player.rl_direction = 0;
	return (1);
}

void	ft_button(t_vars *vars)
{
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_press, vars);
	mlx_hook(vars->win, KeyRelease, KeyReleaseMask, key_release, vars);
	mlx_hook(vars->win, ClientMessage, NoEventMask, ft_close, vars);
}

int	update(t_vars *vars)
{
	cast_all_rays(vars);
	generate3d_projection(vars);
	ft_player_move(vars);
	ft_free(vars->rays);
	return (0);
}

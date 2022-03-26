/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:20:01 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/26 18:26:42 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <RayCasting.h>

void	ft_init_player(t_vars *vars)
{
	t_player	player;
	char		rota;

	rota = ft_find_what(vars->map);
	player.posx = (ft_find_pos(vars->map, rota, 1) * TILE_SIZE)
		+ TILE_SIZE / 2 + 1;
	player.posy = (ft_find_pos(vars->map, rota, 2) * TILE_SIZE)
		+ TILE_SIZE / 2 + 1;
	player.turn_direction = 0;
	vars->door = false;
	player.rl_direction = 0;
	player.walk_direction = 0;
	player.rotation_angle = deg2rad(ft_start_dir(vars));
	player.walk_speed = 3;
	vars->toggle_mouse = false;
	player.turn_speed = deg2rad(5);
	vars->player = player;
}

void	render_colors(t_vars *vars, t_data *img, t_render_3d three_d, int x)
{
	int			y;
	t_data		texture;

	init_texture(vars, &texture);
	y = three_d.wall_bottom_pixel;
	while (++y <= WIN_H)
		img_pix_put(img, x, y, vars->floor);
	y = three_d.wall_top_pixel;
	init_texture_x(vars, &texture, x);
	while (++y <= three_d.wall_bottom_pixel)
	{
		calculate_texture_y(three_d, &texture, y, 4);
		if (vars->rays[x].was_hit_vertical && vars->rays[x].is_ray_facing_right)
			img_pix_put(img, x, y, texture.colors[0]);
		else if (vars->rays[x].was_hit_vertical
			&& vars->rays[x].is_ray_facing_left)
			img_pix_put(img, x, y, texture.colors[1]);
		else if (vars->rays[x].is_ray_facing_up)
			img_pix_put(img, x, y, texture.colors[2]);
		else
			img_pix_put(img, x, y, texture.colors[3]);
	}
	y = -1;
	while (++y <= three_d.wall_top_pixel)
		img_pix_put(img, x, y, vars->cells);
}

void	print_image(t_vars *vars, t_data *img)
{
	ft_minimap(vars, img, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
	mlx_destroy_image(vars->mlx, img->img);
}

void	generate3d_projection(t_vars *vars)
{
	t_data		img;
	t_render_3d	three_d;
	int			x;

	x = -1;
	img.img = mlx_new_image(vars->mlx, vars->win_x, vars->win_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	while (++x < NUM_RAYS)
	{
		three_d.perp_distance = vars->rays[x].distance
			* cos(vars->rays[x].ray_angle - vars->player.rotation_angle);
		three_d.projected_wall_h = (TILE_SIZE / three_d.perp_distance)
			* ((WIN_W / 2) / tan((120 * (M_PI / 180)) / 2));
		three_d.wall_strip_h = (int)three_d.projected_wall_h;
		three_d.wall_top_pixel = (WIN_H / 2) - (three_d.wall_strip_h / 2);
		if (three_d.wall_top_pixel < 0)
			three_d.wall_top_pixel = 0;
		three_d.wall_bottom_pixel = (WIN_H / 2) + (three_d.wall_strip_h / 2);
		if (three_d.wall_bottom_pixel > WIN_H)
			three_d.wall_bottom_pixel = WIN_H;
		render_colors(vars, &img, three_d, x);
	}
	print_image(vars, &img);
}

void	ft_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return ;
	ft_init_player(vars);
	vars->win_x = WIN_W;
	vars->win_y = WIN_H;
	vars->win = mlx_new_window(vars->mlx, vars->win_x, vars->win_y, "Cub3D!");
	vars->floor = get_rgb(vars->path.f_path);
	vars->cells = get_rgb(vars->path.c_path);
	ft_create_textures(vars);
	ft_button(vars);
	mlx_loop_hook(vars->mlx, update, vars);
	mlx_loop(vars->mlx);
}

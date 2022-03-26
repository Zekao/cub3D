/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:13:28 by nabentay          #+#    #+#             */
/*   Updated: 2022/03/06 21:09:59 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <get_next_line.h>
# include <bsd/string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <limits.h>

# define TWO_PI 6.28318530
# define TILE_SIZE 64
# define FLT_MAX 3.402823466e+38F

# define WIN_W 1200
# define WIN_H 800

# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define NUM_RAYS WIN_W

typedef struct s_path
{
	int		f;
	int		c;
	int		no;
	int		so;
	int		we;
	int		ea;
	char	*f_path;
	char	*c_path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}			t_path;

typedef struct render_3d
{
	float	perp_distance;
	float	projected_wall_h;
	int		wall_strip_h;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
}		t_render_3d;

typedef struct s_player {
	float	posx;
	float	posy;
	int		turn_direction;
	int		walk_direction;
	int		rl_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}				t_player;

typedef struct s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				texture_offset_x;
	int				texture_offset_y;
	int				colors[4];
	unsigned int	*wall[4];
}				t_data;

typedef struct s_calcul_rays {
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	x_to_check;
	float	y_to_check;
}					t_rays_c;

typedef struct s_calcul_rays_dist {
	int		wall_content;
	float	wall_hit_y;
	float	wall_hit_x;
	float	touch_y;
	float	touch_x;
	bool	found_wall_hit;
	float	nexttouch_y;
	float	nexttouch_x;
	float	hit_distance;
}					t_rays_dis;

typedef struct s_rays {
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	bool	was_hit_vertical;
	int		wall_hit_content;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
}					t_rays;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	void			*texture_left;
	void			*texture_right;
	void			*texture_up;
	void			*texture_down;
	char			**map;
	struct s_path	path;
	struct s_player	player;
	struct s_rays	*rays;
	int				cells;
	int				floor;
	int				win_x;
	int				win_y;
	int				collectible;
}				t_vars;

int		ft_check_zero(char **map, int y, int x);
int		ft_check_first_last_line(char **map, int y, int x);
int		ft_check_col(char **map, int i, int j);
int		ft_check_player(char **map, int i, int j);
int		ft_check_content(char **map, int i, int j);
int		ft_check_textures(char **map, t_path *path);
int		ft_find_pos(char **map, char c, int type);

char	**recover_map(char *file);
int		ft_get_size(char *file);
int		ft_charcmp(char a, char b);
int		ft_strlen2(char *str);
void	ft_parse_cub(char *str);

char	**ft_create_new(char **map, int i);
char	**adjust_map(char **map);
int		ft_check_line(char *line);
int		ft_strstrlen(char **str);

/* MLX */
void	ft_init(t_vars *vars);
void	ft_button(t_vars *vars);
int		ft_key_hook(int keycode, t_vars *vars);
int		ft_close(t_vars *vars);
void	img_pix_put(t_data *img, int x, int y, int color);
int		update(t_vars *vars);

/* MATH */
double	rad2deg(double degrees);
double	deg2rad(double degrees);
float	distance_between_points(float x1, float y1, float x2, float y2);
float	normalizeangle(float angle);

int		ft_get_col(char **map);
int		ft_get_row(char **map);
char	**ft_fill_new(char **map);
int		ft_start_dir(t_vars *vars);
char	ft_find_what(char **map);
int		get_rgb(char *path);
void	ft_create_textures(t_vars *vars);
void	init_texture_x(t_vars *vars, t_data *texture, int x);
void	calculate_texture_y(t_render_3d three_d, t_data *texture, int y, int i);
void	init_texture(t_vars *vars, t_data *texture);
void	exit_failure2(const char *msg, t_vars *vars);

#endif

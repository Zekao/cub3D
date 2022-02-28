/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 00:20:14 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/28 04:51:53 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include <mlx.h>

int	ft_charcmp(char a, char b)
{

	if (b == 'N' || b == 'W' || b == 'E' || b == 'S')
		return (0);
	else if (a == 'N' || a == 'W' || a == 'E' || a == 'S')
		return (0);
	else if (a - b == 0 || a - b == -1)
		return (0);
	return (42);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_check_zero(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (map[y])
	{
		while (map[y][x] && x <= ft_strlen2(map[y]))
		{
			if (map[y][x] == '0' && x > ft_strlen2(map[y - 1]))
				return (false);
			else if (map[y][x] == '0' && x > ft_strlen2(map[y + 1]))
				return (false);
			else if ((map[y][x] == '0' && ft_charcmp(map[y][x], map[y - 1][x]) != 0))
				return (false);
			else if ((map[y][x] == '0' && ft_charcmp(map[y][x], map[y + 1][x]) != 0))
				return (false);
			else if ((map[y][x] == '0' && ft_charcmp(map[y][x], map[y][x + 1]) != 0))
				return (false);
			else if ((map[y][x] == '0' && ft_charcmp(map[y][x], map[y][x - 1]) != 0))
				return (false);
			x++;
		}
		x = 0;
		y++;
	}
	return (true);
}


int	ft_check_first_last_line(char **map, int y, int x)
{
	if (!*map)
		ft_exit(false);
	while (map[y][x] && x < (int)ft_strlen(map[y]) - 2)
	{
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (false);
		x++;
	}
	x = 0;
	while (map[y])
		y++;
	y -= 1;
	while (map[y][x] && x <= (int)ft_strlen2(map[y]) - 1)
	{
		if (map[y][x] != '1' && map[y][x] != ' ')
			return (false);
		x++;
	}
	return (true);
}

int	ft_check_col(char **map, int i, int j)
{
	while (map[i])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (false);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][(int)ft_strlen(map[i]) - 2] != '1')
			return (false);
		i++;
	}
	return (true);
}

int	ft_check_player(char **map, int i, int j)
{
	int	value;

	value = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
				value++;
			j++;
		}
		i++;
	}
	return (value);
}

int	ft_check_content(char **map, int i, int j)
{
	if (ft_check_player(map, 0, 0) != 1)
		return (false);
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' '
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] !=
				'E' && map[i][j] != 'W' && map[i][j] != '\n')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	ft_get_size(char *file)
{
	int		fd;
	int		size;
	char	*tmp;

	size = 0;
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	size++;
	while (tmp)
	{
		ft_free(tmp);
		tmp = get_next_line(fd);
		size++;
	}
	ft_free(tmp);
	return (size);
}

char	**recover_map(char *file)
{
	char	**map;
	int		fd;
	int		i;
	int		size;

	i = 0;
	fd = open(file, O_RDONLY);
	size = ft_get_size(file);
	map = ft_malloc(sizeof(char *) * size + 1);
	while (i < size - 1)
	{
		map[i] = get_next_line(fd);
		printf("%s", map[i]);
		i++;
	}
	map[i] = '\0';
	close(fd);
	return (map);
}


int	ft_close(t_vars *vars)
{
	ft_free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	printf("Closed\n");
	ft_exit (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		ft_free(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		ft_exit (1);
	}
	return (1);
}

void	ft_button(t_vars *vars)
{
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, ON_DESTROY, 0, ft_close, vars);
}

static inline double	deg2rad(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

static inline double	rad2deg(double degrees)
{
	return (degrees * (180.0 / M_PI));
}

void	ft_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	printf("%f\n", deg2rad(180));
	mlx_get_screen_size(vars->mlx, &vars->win_x, &vars->win_y);
	vars->win = mlx_new_window(vars->mlx, vars->win_x, vars->win_y, "Cub3D!");
	ft_button(vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		vars.map = recover_map(argv[1]);
		if (ft_check_first_last_line(vars.map, 0, 0) == false)
			exit_failure("error in the map ?");
		if (ft_check_col(vars.map, 0, 0) == false)
			exit_failure("error in the map !");
		if (ft_check_content(vars.map, 0, 0) == false)
			exit_failure("error in the map /");
		if (ft_check_zero(vars.map) == false)
			exit_failure("error in the map !!");
		ft_init(&vars);
	}
	else
		printf("%d\n", ft_charcmp('0', 'N'));
}

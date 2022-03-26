/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:34:00 by emaugale          #+#    #+#             */
/*   Updated: 2022/03/04 20:55:04 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	img_pix_put(t_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

/* get color from the path */

int	get_rgb(char *path)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;
	int		res;

	if (!ft_strchr(path, ','))
		exit_failure("Problem in the texture path");
	rgb = ft_split(path, ',');
	if (ft_strstrlen(rgb) < 3)
		exit_failure("Problem in the texture path");
	red = ft_atoi(rgb[0]);
	green = ft_atoi(rgb[1]);
	blue = ft_atoi(rgb[2]);
	res = red << 16 | green << 8 | blue;
	return (res);
}

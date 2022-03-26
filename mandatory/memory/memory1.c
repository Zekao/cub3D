/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:03:01 by ubuntu            #+#    #+#             */
/*   Updated: 2022/03/06 04:01:33 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_exit(int status)
{
	(void)status;
	clear_memory();
	exit(1);
}

void	exit_failure(const char *msg)
{
	printf("\033[1;31m%s\033[m\n", msg);
	ft_exit(1);
}

void	exit_failure2(const char *msg, t_vars *vars)
{
	printf("\033[1;31m%s\033[m\n", msg);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 05:08:57 by emaugale          #+#    #+#             */
/*   Updated: 2022/02/28 16:14:16 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_parse_cub(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i <= 3)
		exit_failure("\033[1;31mError\nThis is not a .cub extension\n\033[m");
	else if (i > 3 && ft_strncmp(str + i - 4, ".cub", 4))
		exit_failure("\033[1;31mError\nThis is not a .cub extension\n\033[m");
	else if (str[ft_strlen(str) - 5] == '/')
		exit_failure("\033[1;31mError\nThis is not a .cub extension\n\033[m");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 20:27:32 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/14 11:22:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *str)
{
	int		i;
	int		i2;
	char	*tab;

	i = ft_strlen(str);
	i2 = -1;
	tab = ft_malloc(sizeof(char) * i + 1);
	if (!tab)
		return (NULL);
	while (++i2 < i)
		tab[i2] = str[i2];
	tab[i2] = '\0';
	return (tab);
}

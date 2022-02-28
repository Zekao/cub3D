/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 22:44:49 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/07 12:02:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;

	new = malloc(sizeof(char) * (size * count));
	if (!new)
		return (NULL);
	ft_memset(new, 0, size * count);
	return (new);
}

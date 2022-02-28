/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:08:28 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/07 12:02:05 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static int	ft_ischarset(char const *set, char str)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_mystrcpy(int i, int len, const char *s1, char *res)
{
	int	i2;

	i2 = 0;
	while (s1[i] && i < len)
	{
		res[i2] = s1[i];
		i++;
		i2++;
	}
	res[i2] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*res;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	while (ft_ischarset(set, s1[i]) == 1)
		i++;
	while (ft_ischarset(set, s1[len - 1]) == 1)
		len--;
	if (len - i < 0)
	{
		res = (char *)malloc(sizeof(char) * 1);
		if (!res)
			return (NULL);
	}
	else
		res = (char *)malloc(sizeof(char) * len - i + 1);
	if (!res)
		return (NULL);
	ft_mystrcpy(i, len, s1, res);
	return (res);
}

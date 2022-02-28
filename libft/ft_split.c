/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:43:58 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/27 20:12:05 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <memory.h>

static size_t	ft_word(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && s++)
	{
		while (*s != c && *s)
			s++;
		cnt++;
		while (*s == c && *s)
			s++;
	}
	return (cnt);
}

static int	ft_fill(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s != c && *s && ++s)
			len++;
		tab[i] = (char *)ft_malloc(sizeof(char) * len + 1);
		if (!tab[i])
		{
			while (i)
				ft_free(tab[--i]);
			ft_free(tab);
			return (1);
		}
		ft_strlcpy(tab[i++], s - len, len + 1);
		while (*s == c && *s)
			s++;
	}
	tab[i] = 0;
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	while (*s == c && *s)
		s++;
	tab = (char **)ft_malloc(sizeof(char *) * (ft_word(s, c) + 1));
	if (!tab)
		return (NULL);
	if (ft_fill(s, c, tab))
		return (NULL);
	return (tab);
}

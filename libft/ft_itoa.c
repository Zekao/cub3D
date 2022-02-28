/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 01:41:54 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/17 15:18:50 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_len_nb(long int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_div(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

static char	*ft_conv(long int n, char *res, int len, int i)
{
	int		len2;

	len2 = len;
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
		i++;
		len--;
	}
	while (i < len2)
	{
		res[i] = ((n / ft_div(len)) % 10) + 48;
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int			i;
	int			len;
	long int	nb;
	char		*res;

	i = 0;
	nb = n;
	len = ft_len_nb(nb);
	res = ft_malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	return (ft_conv(nb, res, len, i));
}

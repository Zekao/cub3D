/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:08:36 by nabentay          #+#    #+#             */
/*   Updated: 2022/02/28 01:17:43 by nabentay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

char	*ft_joinline(ssize_t i, char **file)
{
	char	*res;
	char	*tmp;

	if (i <= 0)
	{
		if (!**file)
		{
			ft_free(*file);
			*file = NULL;
			return (NULL);
		}
		res = *file;
		*file = NULL;
		return (res);
	}
	tmp = ft_substr(*file, i, BUFFER_SIZE);
	res = *file;
	res[i] = 0;
	*file = tmp;
	return (res);
}

char	*ft_line(int fd, char **file, char *buff)
{
	char	*nl;
	char	*tmp;
	ssize_t	i;

	nl = ft_strchr(*file, '\n');
	while (!nl)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0)
			return (ft_joinline(i, file));
		buff[i] = 0;
		tmp = ft_strjoin(*file, buff);
		if (*file)
			ft_free(*file);
		*file = tmp;
		nl = ft_strchr(*file, '\n');
	}
	return (ft_joinline(nl - *file + 1, file));
}

char	*get_next_line(int fd)
{
	static char	*file[1024];
	char		*buff;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buff = (char *)ft_malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!file[fd])
		file[fd] = ft_strdup("");
	res = ft_line(fd, &file[fd], buff);
	if (buff)
		ft_free (buff);
	return (res);
}

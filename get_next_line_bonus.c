/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:39:47 by etamazya          #+#    #+#             */
/*   Updated: 2024/04/14 18:11:32 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_filtr(char *buffer)
{
	char	*temp;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!buffer || !(*buffer))
		return (NULL);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	temp = (char *)malloc((size + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_readfd(int fd, char *buffer)
{
	char	*res;
	int		bytes;

	res = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!res)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && ft_strchr(buffer, '\n') == 0)
	{
		bytes = read(fd, res, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(res);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		res[bytes] = '\0';
		buffer = ft_strjoin(buffer, res);
	}
	free(res);
	res = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer[fd] = ft_readfd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	res = ft_filtr(buffer[fd]);
	if (!res)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_strdup(buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	return (res);
}

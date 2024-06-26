/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:41:22 by etamazya          #+#    #+#             */
/*   Updated: 2024/04/14 17:42:04 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *src)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		j;
	char	*s1_dup;
	int		dir;

	j = 0;
	dir = 0;
	while (s1[dir] && s1[dir] != '\n')
		dir++;
	if (s1[dir] == '\n')
		dir++;
	s1_dup = (char *)malloc((ft_strlen(s1) - dir + 1) * sizeof(char));
	if (!s1_dup)
		return (NULL);
	while (s1[dir] != '\0')
		s1_dup[j++] = s1[dir++];
	s1_dup[j] = '\0';
	free(s1);
	return (s1_dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (i);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:42:23 by etamazya          #+#    #+#             */
/*   Updated: 2024/04/14 17:36:03 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

char	*get_next_line_bonus(int fd);
char	*ft_readfd(int fd, char *buffer);
char	*ft_filtr(char	*buffer);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);

#endif

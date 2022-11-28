/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:08:18 by mghalmi           #+#    #+#             */
/*   Updated: 2022/11/07 18:12:27 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*new_line(int fd, char *static_buffer)
{
	char	*buffer;
	int		size;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size = 1;
	while (!ft_strchr(static_buffer, '\n') && size != 0)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(static_buffer);
			free(buffer);
			return (NULL);
		}
		buffer[size] = '\0';
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	return (static_buffer);
}

char	*fixed_line(char *static_buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_buffer[i])
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	if (static_buffer[i] == '\n')
	{
		line[i] = static_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	if (!static_buffer[i])
	{
		free(static_buffer);
		return (NULL);
	}
	tab = (char *)malloc(sizeof(char) * (ft_strlen(static_buffer) - i + 1));
	if (!tab)
		return (NULL);
	i++;
	j = 0;
	while (static_buffer[i])
		tab[j++] = static_buffer[i++];
	tab[j] = '\0';
	free(static_buffer);
	return (tab);
}

char	*get_next_line(int fd)
{
	char		*ln;
	static char	*static_buffer[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_buffer[fd] = new_line(fd, static_buffer[fd]);
	if (!static_buffer[fd])
		return (NULL);
	ln = fixed_line(static_buffer[fd]);
	static_buffer[fd] = next_line(static_buffer[fd]);
	return (ln);
}

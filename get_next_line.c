/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:12:03 by mghalmi           #+#    #+#             */
/*   Updated: 2022/11/06 19:38:41 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(int fd, char *static_buffer)
{
	char	*buffer;
	int		size;

	size = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (size != 0 && ft_strchr(buffer, '\n') == NULL)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
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
	if (!static_buffer)
		return (NULL);
	while (static_buffer[i] && static_buffer[i] != '\n')
		i++;
	line = ft_substr(static_buffer, 0, i);
	return (line);
}

char	*next_line(char *static_buffer)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
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
	while (static_buffer[i])
		tab[j++] = static_buffer[i++];
	tab[j] = '\0';
	free(static_buffer);
	return (tab);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = new_line(fd, static_buffer);
	if (!static_buffer)
		return (NULL);
	ln = fixed_line(static_buffer);
	static_buffer = next_line(static_buffer);
	return (ln);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:12:03 by mghalmi           #+#    #+#             */
/*   Updated: 2022/11/04 16:57:54 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line(int fd, char *static_buffer)
{
	char	*buffer;
	int	size;

	size = 1;
	buffer = (char *)malloc(sizeof(char) *  (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (size != 0 && ft_strchr(buffer , '\n') == NULL)
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
	return (static_buffer);
}

char	*fixed_line(int fd, char *static_buffer)
{
	int i;

	i = 0;
	static_buffer = line(fd, static_buffer);
	while (static_buffer[i] != '\n')
		i++;
	
	return (ft_substr(static_buffer, 0, i));
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_buffer = fixed_line(fd, static_buffer);
	return (static_buffer);	
}

int main()
{
	int fd;
	char *static_buffer;
	fd = open("text.txt" , O_RDONLY);	
	static_buffer = fixed_line(fd, static_buffer);
	printf("%s\n" , static_buffer);
	static_buffer = fixed_line(fd, static_buffer);
	printf("%s\n" , static_buffer);
}

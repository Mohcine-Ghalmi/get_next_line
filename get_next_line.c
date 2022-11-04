/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:12:03 by mghalmi           #+#    #+#             */
/*   Updated: 2022/11/04 14:36:22 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line(int fd, char *fixed_buffer)
{
	char	*buffer;
	int		size;

	buffer = (char *)malloc(sizeof(char) *  (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (ft_strchr(buffer , '\n') == NULL)
	{
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		fixed_buffer = ft_strjoin(fixed_buffer, buffer);
	}
	return (fixed_buffer);
}

char	*fixed_line(int fd, char *fixed_buffer)
{
	
}

int main()
{
	int fd;
	static char * fixed_beffer;
	fd = open("text.txt" , O_RDONLY);	
	printf("%s" , line(fd, fixed_beffer));
}

// char	*get_next_line(int fd)
// {
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
		
// }
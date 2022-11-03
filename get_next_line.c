/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:12:03 by mghalmi           #+#    #+#             */
/*   Updated: 2022/11/03 13:42:27 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
	
// }

//count lines
int main()
{
	int fd;
	char tab[1000];
	
	fd = open("text.txt", O_RDONLY);
	read(fd, tab, 5);
	printf("%s" , tab);
}

// size_t count_lines(int fd)
// {
	
// }
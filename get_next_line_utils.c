/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:40:03 by mghalmi           #+#    #+#             */
/*   Updated: 2022/11/04 13:40:39 by mghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

    if (!s)
        return (0);
	i = 0;
	while (s[i])
	i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	find = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*cp;
	int		i;
    
	i = ft_strlen(s1);
	cp = (char *) malloc((sizeof(char) * i + 1));
	if (!cp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cp[i] = s1[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
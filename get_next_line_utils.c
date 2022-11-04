/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mghalmi <mghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:40:03 by mghalmi           #+#    #+#             */
/*   Updated: 2022/11/04 16:21:31 by mghalmi          ###   ########.fr       */
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


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)dst;
	str2 = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
	{
		*(str1++) = *(str2++);
	}
	return ((void *)dst);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*dt;
	char	*sr;

	dt = (char *)dest;
	sr = (char *)src;
	if (!src && !dest)
		return (NULL);
	if (dt >= sr)
		while (len-- > 0)
			dt[len] = sr[len];
	else
		ft_memcpy(dt, sr, len);
	return ((void *)dt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	result = ft_memmove(result, s + start, len);
	return (result);
}

